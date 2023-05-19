/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:39:30 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/19 22:39:37 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	st_pr(int *pp, char **av, char **env)
{
	static char	*cmd1;
	int			fd1;
	
	cmd1 = ft_check_args_1(av, env);
	fd1 = open(av[1], O_RDONLY);
	if (dup2(fd1, 0) == -1)
		printf("error");
	close(fd1);
	close(pp[0]);
	if (dup2(pp[1], 1) == -1)
	close(pp[1]);
	execve(cmd1, ft_split(av[2], ' '), env);
}

void	nd_pr(int *pp, char **av, char **env)
{
	static char	*cmd2;
	int 		fd2;
	cmd2 = ft_check_args_2(av, env);
	fd2 = open(av[4], O_WRONLY | O_TRUNC , 0666);
	close(pp[1]);
	if (dup2(pp[0], 0)== -1)
		ft_printf("error");
	close(pp[0]);
	if (dup2(fd2, 1) == -1)
		ft_printf("error");
	close(fd2);
	execve(cmd2, ft_split(av[3], ' '), env);
}