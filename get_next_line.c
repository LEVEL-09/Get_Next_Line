/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:09:15 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/13 17:34:13y mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>
static char	*ft_substr(char *str)
{
	int		i;
	char	*p;

	i = 0;
	while (str[i])
	{
		if (str[i++] == '\n')
			break ;
	}
	p = malloc(i + 1);
	p[i] = '\0';
	while (i-- > 0)
	{ 
		p[i] = str[i];
	}
	return (p);
}

static int ft_check(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == '\n')
			return (i);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (1)
	{
		int fill = read(fd, buf, BUFFER_SIZE);
		if (fill < 0)
			return (NULL);
		buf[fill] = '\0';
		line = ft_strjoin(line, buf);
		if (!line)
			return NULL;
		if (ft_check(line, '\n') != -1)
		{
			break ;
		}
	}
	return(ft_substr(line));
}
