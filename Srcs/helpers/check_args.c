/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:54:15 by yes-slim          #+#    #+#             */
/*   Updated: 2023/03/16 20:59:08 by yes-slim         ###   ########.fr       */
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

void	check_cmd_path(char **path, char ***cmd, int *c1, int *c2)
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
			(*c1)++;
		free(tmp);
		tmp = ft_join(path[i], cmd[1][0], 0);
		if (!access(tmp, X_OK))
			(*c2)++;
		free(tmp);
		i++;
	}
	ft_free(cmd[0]);
	ft_free(cmd[1]);
	free(cmd);
}

void	check_cmd(char **av, char **env)
{
	char			**path;
	char			***cmd;
	static int		c1;
	static int		c2;
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
	check_cmd_path(path, cmd, &c1, &c2);
	ft_free(path);
	if (!c1 || !c2)
		ft_error(1);
}

void	check_file(char **av)
{
	if (open(av[1], O_RDONLY) == -1)
	{
		if (!access(av[1], R_OK))
			ft_error(3);
		else
			ft_error(2);
	}
	if (open(av[4], O_WRONLY | O_CREAT | O_TRUNC) == -1)
	{
		if (!access(av[4], W_OK))
			ft_error(3);
		else
			ft_error(2);
	}
	
}

void	check_args(char **av, char **env)
{
	check_cmd(av, env);
	check_file(av);
}
