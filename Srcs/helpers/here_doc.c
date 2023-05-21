/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:58:07 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/21 11:46:45 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_heredoc(char **av)	
{
	int		tmp_fd;
	char	*line;
	
	tmp_fd = open("/tmp/.tmp_file", O_CREAT | O_RDWR, 0666);
	line = get_next_line(0);
	while (ft_strncmp(line, av[2], ft_strlen(av[2])) != 0)
	{
		write(tmp_fd, line, ft_strlen(line + 1));
		write(tmp_fd, "\n", 1);
		line = get_next_line(0);
	}
}

void	st_pr_hd(int *pp, char **av, char **env, char *path)
{
	static char	*cmd1;
	int			fd1;
	
	cmd1 = get_path(av[3], env);
	fd1 = open(path, O_RDONLY);
	if (dup2(fd1, 0) == -1)
		//error managment
	close(fd1);
	close(pp[0]);
	if (dup2(pp[1], 1) == -1)
		//error managment
	close(pp[1]);
	execve(cmd1, ft_split(av[3], ' '), env);
}

void	nd_pr_hd(int *pp, char **av, char **env)
{
	static char	*cmd2;
	int 		fd2;
	
	cmd2 = get_path(av[4], env);
	fd2 = open(av[5], O_WRONLY | O_APPEND , 0666);
	close(pp[1]);
	if (dup2(pp[0], 0)== -1)
		//error managment
	close(pp[0]);
	if (dup2(fd2, 1) == -1)
		//error managment
	close(fd2);
	execve(cmd2, ft_split(av[4], ' '), env);
}

void	here_doc(char **av, char **env)
{
	pid_t	pid_c1;
	pid_t	pid_c2;
	int		pp[2];

	read_heredoc(av);
	pipe(pp);
	pid_c1 = fork();
	if (pid_c1 == 0)
		st_pr_hd(pp, av, env, "/tmp/.tmp_file");
	pid_c2 = fork();
	if (pid_c2 == 0)
	{
		check_outfile_HD(av[5]);
		nd_pr_hd(pp, av, env);
	}
	close(pp[0]);
	close(pp[1]);
	waitpid(pid_c1, NULL, 0);
	waitpid(pid_c2, NULL, 0);
	unlink("/tmp/.tmp_file");
	exit(0);
}
