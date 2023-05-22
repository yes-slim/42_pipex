/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:23:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/22 19:10:14 by yes-slim         ###   ########.fr       */
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

char	*get_cmd(char **cmd, char **env)
{
	char	**path;
	char	*tmp;
	int		i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
	path = ft_split(env[i], ':');
	if (!path)
		ft_error(0);
	i = 0;
	while (path[i])
	{
		path[i] = ft_join(path[i], "/", 1);
		tmp = ft_join(path[i++], cmd[0], 0);
		if (!access(tmp, X_OK))
		{
			ft_free(path);
			return (tmp);
		}
		free(tmp);
	}
	ft_free(path);
	return (NULL);
}

char	*get_path(char *av, char **env)
{
	char	*path;
	char	**cmd;

	if (!av[0])
		ft_error_exit(1);
	cmd = ft_split(av, ' ');
	if (!cmd)
		ft_error(0);
	if (cmd[0][0] == '/' || cmd[0][0] == ' ' || cmd[0][0] == '\t')
	{
		if (cmd[0][0] == ' ' || cmd[0][0] == '\t')
			ft_error(1);
		path = ft_strdup(cmd[0]);
		if (access(path, X_OK) == -1)
			ft_error_exit(4);
		ft_free(cmd);
		return (path);
	}
	path = get_cmd(cmd, env);
	if (!path)
		ft_error(1);
	ft_free(cmd);
	return (path);
}
