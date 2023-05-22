/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:09:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/22 01:53:29 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	st_child(char **env, int *pp, char *path, char *cmd)
{
	char	*cmd1;
	int		fd1;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{	
		check_infile(path);
		cmd1 = get_path(cmd, env);
		fd1 = open(path, O_RDONLY);
		if (dup2(fd1, 0) == -1)
			ft_error_exit(0);
		close(fd1);
		close(pp[0]);
		if (dup2(pp[1], 1) == -1)
			ft_error_exit(0);
		close(pp[1]);
		execve(cmd1, ft_split(cmd, ' '), env);
	}
	dup2(pp[0], 0);
	close(pp[0]);
	close(pp[1]);
	waitpid(pid, NULL, 0);
}

void	last_child(int ac, char **av, char **env)
{
	char	*cmd2;
	int		fd2;
	pid_t	pid;

	check_outfile(av[ac - 1]);
	cmd2 = get_path(av[ac - 2], env);
	if (!ft_strncmp(av[1], "here_doc", 9))
	fd2 = open(av[ac - 1], O_WRONLY | O_APPEND, 0666);
	else
		fd2 = open(av[ac - 1], O_WRONLY | O_TRUNC, 0666);
	pid = fork();
	if (pid == 0)
	{
		if (dup2(fd2, 1) == -1)
			ft_error_exit(0);
		close(fd2);
		execve(cmd2, ft_split(av[ac - 2], ' '), env);
	}
	close(fd2);
	waitpid(pid, NULL, 0);
}

void	mid_childs(char *av, char **env)
{
	char	*cmd;
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		cmd = get_path(av, env);
		dup2(fd[1], 1);
		close(fd[0]);
		execve(cmd, ft_split(av, ' '), env);
	}
	dup2(fd[0], 0);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}
