/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:34:26 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/22 01:55:59 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infile(char *path)
{
	if (open(path, O_RDONLY) == -1)
	{
		if (access(path, F_OK) == -1)
			ft_error(2);
		else
			ft_error(3);
		return (0);
	}
	return (1);
}

int	check_outfile(char *path)
{
	if (open(path, O_CREAT | O_WRONLY, 0666) == -1)
	{
		if (access(path, W_OK) == -1)
			ft_error(3);
		return (0);
	}
	return (1);
}
