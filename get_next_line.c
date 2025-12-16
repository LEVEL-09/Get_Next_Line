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
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	int			posix;
	int			index;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	posix = read(fd, buf, BUFFER_SIZE);
	if (posix <= 0)
	{
		free(buf);
		return (NULL);
	}
	buf[BUFFER_SIZE + 1] = '\0';
	index = ft_search(buf, '\n');
	line = ft_strjoin(line, buf, index);
	free(buf);
}
