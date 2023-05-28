/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yes-slim <yes-slim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:41:12 by yes-slim          #+#    #+#             */
/*   Updated: 2023/05/28 18:15:52 by yes-slim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > OPEN_MAX)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	ret = ft_fill(str[fd]);
	str[fd] = ft_remainder(str[fd]);
	return (ret);
}

char	*ft_read(int fd, char *str)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(str, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free (str);
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*ft_fill(char *str)
{
	char	*ret;
	int		i;
	int		z;

	i = 0;
	z = 0;
	if (!ft_strlen(str))
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	while (z < i && str[z])
	{
		ret[z] = str[z];
		z++;
	}
	ret[z] = '\0';
	return (ret);
}

char	*ft_remainder(char *str)
{
	char	*remainder;
	int		i;
	int		z;

	i = 0;
	z = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	i++;
	remainder = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!remainder)
	{
		free (str);
		return (NULL);
	}
	while (str[i])
		remainder[z++] = str[i++];
	remainder[z] = '\0';
	free (str);
	return (remainder);
}
