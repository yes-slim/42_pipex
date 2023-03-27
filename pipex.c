/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:22:43 by yes-slim          #+#    #+#             */
/*   Updated: 2023/03/27 18:24:02 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	static char	*cmd1;
	static char	*cmd2;
	pid_t		pid;
	
	if (ac != 5)
		exit(1);
	pid = fork();
	{
		if (pid > 0)
		{
			cmd1 = ft_check_args_1(av, env);
		}
		else
		{
			cmd2 = ft_check_args_2(av, env);
		}
	}
	// system("leaks pipex");
}
