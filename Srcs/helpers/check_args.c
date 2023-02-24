/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:54:15 by yes-slim          #+#    #+#             */
/*   Updated: 2023/02/24 16:16:02 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_cmd(char **av, char *env)
{
	char			**path;
	char			*tmp;
	static int		i;
	static int		c1;
	static int		c2;

	path = ft_split(env, ':');
	if (!path)
		ft_error(0);
	while (path[i])
	{
		path[i] = ft_join(path[i], "/");
		tmp = ft_join(path[i], av[2]);
		if (access(tmp, X_OK))
			c1++;
		tmp = ft_join(path[i], av[3]);
		if (access(tmp, X_OK))
			c2++;
		i++;
	}
	while (--i)
		free(path[i]);
	free(path);
	if (!c1 || !c2)
		ft_error(1);
}

void	check_file(char *av)
{
	if (open(av, O_RDONLY) == -1)
		ft_error(2);
}

void	check_args(char **av, char *env)
{
	check_cmd(av, env);
	check_file(av[1]);
}
