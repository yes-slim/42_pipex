/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:54:15 by yes-slim          #+#    #+#             */
/*   Updated: 2023/03/21 18:05:25 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	check_cmd_path(char **path, char ***cmd, char **c1, char **c2)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (path[i])
	{
		path[i] = ft_join(path[i], "/", 1);
		tmp = ft_join(path[i], cmd[0][0], 0);
		if (!access(tmp, X_OK))
			*c1 = ft_strdup(tmp);
		free(tmp);
		tmp = ft_join(path[i], cmd[1][0], 0);
		if (!access(tmp, X_OK))
			*c2 = ft_strdup(tmp);;
		free(tmp);
		i++;
	}
	ft_free(cmd[0]);
	ft_free(cmd[1]);
	free(cmd);
}

void	check_cmd(char **av, char **env, char **cmd1, char **cmd2)
{
	char			**path;
	char			***cmd;
	static int		i;

	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
		i++;
	}
	cmd = malloc(sizeof(char **) * 2);
	if (!cmd)
		ft_error(0);
	path = ft_split(env[i], ':');
	cmd[0] = ft_split(av[2], ' ');
	cmd[1] = ft_split(av[3], ' ');
	if (!path || !cmd[0] || !cmd[1])
		ft_error(0);
	check_cmd_path(path, cmd, cmd1, cmd2);
	ft_free(path);
	if (!(*cmd1) || !(*cmd2))
		ft_error(1);
}

void	check_file(char **av)
{
	if (open(av[1], O_RDONLY) == -1)
	{
		if (access(av[1], F_OK) == -1)
			ft_error(2);
		else
			ft_error(3);
	}
	if (open(av[4], O_WRONLY | O_TRUNC) == -1)
	{
		if (access(av[4], F_OK) == -1)
			ft_error(2);
		else
			ft_error(3);
	}
	
}

void	check_args(char **av, char **env, char **cmd1, char **cmd2)
{
	check_cmd(av, env, cmd1, cmd2);
	check_file(av);
}
