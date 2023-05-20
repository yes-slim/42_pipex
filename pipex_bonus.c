/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:31:20 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/20 15:30:47 by yes-slim         ###   ########.fr       */
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
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		here_doc(av, env);
		exit(0);
	}
}
