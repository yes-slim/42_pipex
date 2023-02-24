/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:50:49 by yes-slim          #+#    #+#             */
/*   Updated: 2023/02/23 18:54:41 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_print_adr(unsigned long l, int *len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (l >= 16)
		ft_print_adr((l / 16), len);
	ft_print_char(hex[l % 16], len);
}

void	ft_print_char(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_print_str(char *str, int *len)
{
	int	i;

	if (str)
	{
		i = 0;
		while (str[i])
		{
			ft_print_char(str[i], len);
			i++;
		}
	}
	else
		(*len) += write(1, "(null)", 6);
}

void	ft_print_nbr(int i, int *len)
{
	if (i == INT_MIN)
		ft_print_str("-2147483648", len);
	else if (i < 0)
	{
		ft_print_char('-', len);
		i *= -1;
	}
	if (i > 9)
	{
		ft_print_nbr((i / 10), len);
		ft_print_nbr((i % 10), len);
	}
	if (i >= 0 && i <= 9)
		ft_print_char((i + '0'), len);
}
