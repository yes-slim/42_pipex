/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:22:04 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/22 21:22:07 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int err)
{
	if (err == 0)
		ft_printf("Error\n");
	if (err == 1)
		ft_printf("Error: command not found\n");
	if (err == 2)
		ft_printf("Error: file not found\n");
	if (err == 3)
		ft_printf("Error: permission denied\n");
	if (err == 4)
		ft_printf("Error: no such file or directory\n");
	if (err == 8)
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
	if (err == 9)
		ft_printf("Error: invalid arguments\n");
}

void	ft_error_exit(int err)
{
	if (err != -1)
		ft_error(err);
	exit(1);
}
