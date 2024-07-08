/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:59:34 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/07/08 18:09:08 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	while (*s)
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (unsigned int)ft_strlen(s + start))
		len = (unsigned int)ft_strlen(s + start);
	str = calloc(len + 1, sizeof(char));
	if (str == 0)
	{
		return (NULL);
	}
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

char	*set(char *line)
{
	int		i;
	char	*stock;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	stock = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (stock == 0)
	{
		free(stock);
		stock = NULL;
	}
	line[i + 1] = 0;
	return (stock);
}

char	*lect(char *stock, char *buffer, int fd)
{
	int		check;
	char	*temp;
paul-f4Br2s2% cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
	check = 1;
	while (check > 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check < 0)
			return (NULL);
		buffer[check] = '\0';
		if (!stock)
			stock = ft_strdup("");
		temp = stock;
		stock = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;
	char		*buffer;

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free(buffer);
		free(stock);
		stock = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = lect(stock, buffer, fd);
	free(buffer);
	buffer = NULL;
	stock = set(line);
	return (line);
}
