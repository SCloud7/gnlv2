/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:37:56 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/07/08 17:17:44 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*ss;
	size_t	i;

	p = (NULL);
	ss = (char *)p;
	i = 0;
	p = malloc(nmemb * (size));
	if (p == NULL)
		return (NULL);
	while (i < size)
	{
		ss[i] = 0;
		i++;
	}
	return (p);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
		j++;
	c = malloc(j * sizeof(const char) + 1);
	if (c == NULL)
		return (NULL);
	while (s[i])
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ss = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), (sizeof(char)));
	if (ss == NULL)
		return (NULL);
	while (s1[i])
	{
		ss[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ss[i + j] = s2[j];
		j++;
	}
	return (ss);
}
