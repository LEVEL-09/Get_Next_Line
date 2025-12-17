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

static int	ft_search(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i++] == (const char)c)
			return (i);
	}
	return (-1);
}

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	int			find;


	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (1)
	{
		if (!read(fd, buf, BUFFER_SIZE))
		{
			free(line);
			return (NULL);
		}
		buf[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buf);
		find = ft_search(line, '\n');
		if (find != -1)
		{
			ft_strncpy(buf, line, find);
			ft_strncpy(line, line + find, ft_strlen(line) - ft_strlen(buf));
			return (buf);
		}
	}
}
