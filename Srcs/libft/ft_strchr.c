/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:53:51 by yes-slim          #+#    #+#             */
/*   Updated: 2023/03/21 20:39:43 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	if ((char)c == '\0')
		return ((char *)&str[i]);
	i = 0;
	while (str[i] != (char)c && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	return ((char *)&str[i]);
}
