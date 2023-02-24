/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:50:19 by yes-slim          #+#    #+#             */
/*   Updated: 2023/02/23 18:54:46 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_format(const char c, va_list ap, int *len)
{
	if (c == 'c')
		ft_print_char(va_arg(ap, int), len);
	else if (c == 's')
		ft_print_str(va_arg(ap, char *), len);
	else if (c == 'd' || c == 'i')
		ft_print_nbr(va_arg(ap, int), len);
	else if (c == 'p')
	{
		(*len) += write(1, "0x", 2);
		ft_print_adr(va_arg(ap, unsigned long), len);
	}	
	else if (c == '%')
		(*len) += write(1, "%", 1);
	else
		(*len) += write(1, &c, 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			check_format(str[i], args, &len);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
