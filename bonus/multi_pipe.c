/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:03:40 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/22 01:54:01 by yes-slim         ###   ########.fr       */
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
		write(tmp_fd, line, ft_strlen(line));
		write(tmp_fd, "\n", 1);
		line = get_next_line(0);
	}
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
