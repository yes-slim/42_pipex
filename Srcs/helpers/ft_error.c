/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:22:04 by yes-slim          #+#    #+#             */
/*   Updated: 2023/03/22 16:09:34 by yes-slim         ###   ########.fr       */
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
	// exit(1);
}
