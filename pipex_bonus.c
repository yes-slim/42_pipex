/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:31:20 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/21 15:46:49 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_multi(char **av, char **env, int i, int *pp)
{
	static char	*cmd;
	pid_t		pid;
	
	pipe(pp);
	pid = fork();
	if (pid == 0)
	{
		dup2(pp[1], 1);
		close(pp[0]);
		cmd = get_path(av[i], env);
		execve(cmd, ft_split(av[i], ' '), env);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(pp[1]);
		dup2(pp[0], 0);
	}
}

void	st_cmd(char **av, char **env, int *pp)
{
	check_infile(av[1]);
	st_pr(pp, av, env, av[1]);	
}

void	nd_cmd(int ac, char **av, char **env, int *pp)
{
	check_outfile(av[ac - 1]);
	nd_pr(pp, av, env);
}

void	multi_pipe(int ac, char **av, char **env)
{
	pid_t		pid_c1;
	pid_t		pid_c2;
	int			i;
	int			pp[2];
	int			pp_2[2];

	i = 3;
	pipe(pp);
	pid_c1 = fork();
	if (pid_c1 == 0)
		st_cmd(av, env, pp);
	dup2(pp[0], 0);
	close(pp[1]);
	while (i < ac - 2)
	{
		ft_multi(av, env, i, pp_2);
		i++;
	}
	pid_c2 = fork();
	if (pid_c2 == 0)
		nd_cmd(ac, av, env, pp_2);
	close(pp[0]);
	close(pp[1]);
	waitpid(pid_c1, NULL, 0);
	waitpid(pid_c2, NULL, 0);	
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		exit(1);
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		here_doc(av, env);
	multi_pipe(ac, av, env);
	return (0);
}
