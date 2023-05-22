/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:22:43 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/22 18:10:49 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	pid_t		pid_c1;
	pid_t		pid_c2;
	int			pp[2];

	if (ac != 5)
		exit(1);
	pipe(pp);
	pid_c1 = fork();
	if (pid_c1 == 0)
	{
		check_infile(av[1]);
		st_pr(pp, av, env, av[1]);
	}
	pid_c2 = fork();
	if (pid_c2 == 0)
	{
		check_outfile(av[4]);
		nd_pr(pp, av[3], av[4], env);
	}
	close(pp[0]);
	close(pp[1]);
	waitpid(pid_c1, NULL, 0);
	waitpid(pid_c2, NULL, 0);
}
