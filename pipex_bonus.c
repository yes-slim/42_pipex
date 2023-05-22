/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:31:20 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/22 21:22:27 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		ft_error_exit(9);
	multi_pipe(ac, av, env);
}

void	read_heredoc(char **av)
{
	int		tmp_fd;
	char	*line;

	tmp_fd = open("/tmp/.tmp_file", O_CREAT | O_RDWR, 0666);
	line = get_next_line(0);
	if (!line)
		exit(1);
	while (ft_strncmp(line, av[2], ft_strlen(av[2])) != 0)
	{
		write(tmp_fd, line, ft_strlen(line));
		write(tmp_fd, "\n", 1);
		free(line);
		line = get_next_line(0);
		if (!line)
			exit(1);
	}
	free(line);
}

void	multi_pipe(int ac, char **av, char **env)
{	
	int	start;
	int	md[2];

	pipe(md);
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		start = 3;
		read_heredoc(av);
		st_child(env, md, "/tmp/.tmp_file", av[3]);
		unlink("/tmp/.tmp_file");
	}
	else
	{
		start = 2;
		st_child(env, md, av[1], av[2]);
	}
	while (start < ac - 2)
		mid_childs(av[start++], env);
	last_child(ac, av, env);
}
