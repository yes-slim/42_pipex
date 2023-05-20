/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:31:20 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/20 11:41:17 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	pid_t		pid_c1;
	pid_t		pid_c2;
	int			pp[2];
	int			tmp_fd;
	if (ac < 5)
		exit(1);
	tmp_fd = open("/tmp/.tmp_file", O_CREAT | O_RDWR, 0666);
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		char *line = get_next_line(0);
		while (ft_strncmp(line, av[2], ft_strlen(av[2])) != 0)
		{
			write(tmp_fd, line, ft_strlen(line + 1));
			line = get_next_line(0);
		}
	}
	// pipe(pp);1
	// pid_c1 = fork();
	// if (pid_c1 == 0)
	// 	st_pr(pp, av, env , 0);
	// pid_c2 = fork();
	// if (pid_c2 == 0)
	// 	nd_pr(pp, av, env);
	// close(pp[0]);
	// close(pp[1]);
	// waitpid(pid_c1, NULL, 0);
	// waitpid(pid_c2, NULL, 0);
	// unlink("/tmp/.tmp_file");
}
