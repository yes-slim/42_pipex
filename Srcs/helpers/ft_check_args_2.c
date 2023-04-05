/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:23:34 by yes-slim          #+#    #+#             */
/*   Updated: 2023/03/30 11:16:14 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_cmd_2(char **cmd, char **env)
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

int	check_file_2(char *path)
{
	if (open(path, O_WRONLY | O_TRUNC) == -1)
	{
		if (access(path, W_OK) == -1)
			ft_error(3);
		return(0);
	}
	return (1);
}

char	*ft_check_args_2(char **av, char **env)
{
	char	*path;
	char	**cmd;

	if (!check_file_2(av[4]))
		ft_error_exit(-1);
	cmd = ft_split(av[3], ' ');
	if (!cmd)
		ft_error(0);
	if (cmd[0][0] == '/' || cmd[0][0] == ' ' || cmd[0][0] == '\t')
	{
		if (cmd[0][0] == ' ' || cmd[0][0] == '\t')
			ft_error(1);
		path = ft_strdup(cmd[0]);
		if (access(path, X_OK) == -1)
			ft_error(4);
		ft_free(cmd);
		return(path);
	}
	path = check_cmd_2(cmd, env);
	if (!path)
		ft_error(1);
	ft_free(cmd);
	return(path);
}
