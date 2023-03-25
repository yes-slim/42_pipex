/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:22:43 by yes-slim          #+#    #+#             */
/*   Updated: 2023/03/25 16:47:18 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	static char	*cmd1;
	static char	*cmd2;
	pid_t		pid;
	
	if (ac != 5)
		exit(1);
	cmd1 = ft_check_args_1(av, env);
	cmd2 = ft_check_args_2(av, env);
	// printf("%s\n%s\n", cmd1, cmd2);
	// system("leaks pipex");
}
