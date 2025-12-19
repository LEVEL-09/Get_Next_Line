/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:09:15 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/19 21:34:36 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <string.h>
#include <stdio.h>
static int	ft_check(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}

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
	if (!p)
		return (NULL);
	p[i] = '\0';
	while (i-- > 0)
		p[i] = str[i];
	return (p);
}

static char	*ft_subjoin(char *str)
{
	char	*ptr;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	i = ft_check(str, '\n');
	if (i == -1)
		i = 0;
	len = ft_strlen(str + i);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr = ft_strncpy(ptr, str + i, len + 1);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	int			fill;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	while (1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		fill = read(fd, buf, BUFFER_SIZE);
		if (fill == 0)
			return (line);
		buf[fill] = '\0';
		line = ft_strjoin(line, buf);
		if (ft_check(line, '\n') || ft_check(line, '\0'))
		{
			free(buf);
			buf = ft_substr(line);
			line = ft_subjoin(line);
			return (buf);
		}
	}
}
