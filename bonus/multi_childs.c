/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:09:45 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/21 23:11:06 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	st_child(char **av, char **env, int *pp, int *fd)
{
	static char	*cmd1;
	int 		fd1;
	
	check_infile(av[1]);
	cmd1 = get_path(av[3], env);
	fd1 = open(av[1], O_RDONLY);
	if (dup2(fd1, 0) == -1)
		// exit(1);
	close(fd1);
	close(pp[0]);
	if (dup2(pp[1], 1) == -1)
		// exit(1);
	close(pp[1]);
	*fd = fd1;
	execve(cmd1, ft_split(av[2], ' '), env);
}

void	last_child(int ac, char **av, char **env, int *pp)
{
	static char	*cmd2;
	int 		fd2;
	
	check_outfile(av[ac - 1]);
	cmd2 = get_path(av[ac - 2], env);
	fd2 = open(av[ac - 1], O_WRONLY | O_TRUNC , 0666);
	close(pp[1]);
	if (dup2(pp[0], 0)== -1)
		// exit(1);
	close(pp[0]);
	if (dup2(fd2, 1) == -1)
		// exit(1);
	close(fd2);
	execve(cmd2, ft_split(av[ac - 2], ' '), env);
}
void	mid_childs(char *av, char **env, int *pp_1, int *pp_2)
{
	char	*cmd;
	
	dup2(pp_2[1], 1);
	close(pp_2[0]);
	dup2(pp_1[0], 0);
	close(pp_1[1]);
	pp_2[0] = pp_1[0];                                                                                                                                                                                                                                       
	cmd = get_path(av, env);
	execve(cmd, ft_split(av, ' '), env);
}
