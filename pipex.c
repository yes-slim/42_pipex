/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:22:43 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/19 18:06:29 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	static char	*cmd1;
	static char	*cmd2;
	pid_t		pid_c1;
	pid_t		pid_c2;
	int			pp[2];
	int			fd1;
	int 		fd2;
	
	if (ac != 5)
		exit(1);
	pipe(pp);
	pid_c1 = fork();
	if (pid_c1 == 0)
	{
		cmd1 = ft_check_args_1(av, env);
		fd1 = open(av[1], O_RDONLY);
		if (dup2(fd1, 0) == -1)
			printf("error");
		close(fd1);
		close(pp[0]);
		if (dup2(pp[1], 1) == -1)
			printf("error");
		dprintf(1,"4-0\n");
		close(pp[1]);
		execve(cmd1, ft_split(av[2], ' '), env);
	}
	pid_c2 = fork();
	if (pid_c2 == 0)
	{
		cmd2 = ft_check_args_2(av, env);
		fd2 = open(av[4], O_WRONLY | O_TRUNC , 0666);
		close(pp[1]);
		if (dup2(pp[0], 0)== -1)
		close(pp[0]);
		if (dup2(fd2, 1) == -1)
		close(fd2);
		execve(cmd2, ft_split(av[3], ' '), env);
	}
	close(pp[0]);
	close(pp[1]);
	waitpid(pid_c1, NULL, 0);
	waitpid(pid_c2, NULL, 0);
	system("leaks pipex");
}
