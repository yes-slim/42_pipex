/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:03:40 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/21 23:02:13 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	multi_pipe(int ac, char **av, char **env)
{
	pid_t	*pid;
	int 	**pp;
	int 	i;
	int 	n;
	int 	fd;
	
	pp = malloc(sizeof(int *) * (ac - 4));
	pid = malloc(sizeof(pid_t) * (ac - 3));
	n = 0;
	while (n < ac - 4)
		pipe(pp[n++]);
	n = 0;
	i = 3;
	while (n <= ac - 3)
	{
		pid[n] = fork();
		if (pid[n] == 0)
		{
			if (n == 0)
			{
				st_child(av, env, pp[n], &fd);
				pp[n][0] = fd;
			}
			else if (n == ac - 3)
				last_child(ac, av, env, pp[n]);
			else
				mid_childs(av[i], env, pp[n], pp[n + 1]);
		}
		i++;
		n++;
		close(pp[n][0]);
		close(pp[n][1]);
		waitpid(pid[n], NULL, 0);
	}
}
 