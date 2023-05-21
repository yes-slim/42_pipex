/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 22:31:20 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/21 11:35:50 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int ac, char **av, char **env)
{
	if (ac <= 5)
		exit(1);
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		here_doc(av, env);
	// multi_pipe(ac, av, env);
}

// void	multi_pipe(int ac, char **av, char **env)
// {
// 	pid_t		pid_c1;
// 	pid_t		pid_c2;
// 	pid_t		pid_c2;
// 	int			i;
// 	int			pp[2];
// 	int			tmp_fd;

// 	i = 2;
// 	pipe(pp);
// 	pid_c1 = fork();
// 	if (pid_c1 == 0)
// 		st_cmd(av, env, pp);
// 	pid_c3 = fork();
// 	if (pid_c3 == 0)
// 		ft_multi(av, env);
// 	while (++i < ac -2)
// 	{
// 		pid_c2 = fork();
// 		if (pid_c2 == 0)
// 			ft_multi(av, env, i);
// 	}
// 	if (pid_c2 == 0)
// 		nd_cmd(av, env, pp);
// 	close(pp[0]);
// 	close(pp[1]);
// 	waitpid(pid_c1, NULL, 0);
// 	waitpid(pid_c2, NULL, 0);	
// }

// void	ft_multi(char **av, char **env, int i)
// {
// 	static char	*cmd;
// 	int			fd;
	
// 	cmd = get_path(av[], env);
// 	fd = open(path, O_RDONLY);
// 	if (dup2(fd, 0) == -1)
// 		// exit(1);
// 	close(fd);
// 	close(pp[0]);
// 	if (dup2(pp[1], 1) == -1)
// 		// exit(1);
// 	close(pp[1]);
// 	execve(cmd, ft_split(av[2], ' '), env);
// }

// void	st_cmd(char **av, char **env, int *pp)
// {
// 	check_infile(av[1]);
// 	st_pr(pp, av, env, av[1]);	
// }

// void	nd_cmd(char **av, char **env, int *pp)
// {
// 	check_outfile(av[ac - 1]);
// 	nd_pr(pp, av, env);
// }
