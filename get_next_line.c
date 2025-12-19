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

static int ft_check(char *s)
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
	i = ft_check(str);
	if (i == -1)
		i = 0;
	printf("%d \n", i);
	len = ft_strlen(str+i);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr = ft_strncpy(ptr, str+i, len + 1);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	int 		fill;

	while (1)
	{
		buf = malloc(BUFFER_SIZE + 1);
		fill = read(fd, buf, BUFFER_SIZE);
		if (fill < 0)
			return (NULL);
		buf[fill] = '\0';
		line = ft_strjoin(line, buf);
		if (ft_check(line) != -1)
		{
			free(buf);
			buf = ft_substr(line);
			line = ft_subjoin(line);
			return (buf);
		}
	}

}
