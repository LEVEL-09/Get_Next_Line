/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:20:26 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/09 12:56:40 mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (dest == src)
		return (dest);
	ptr = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static size_t	i;
	char			*buf;
	char 			*line;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	while (i < BUFFER_SIZE)
	{
		if (buf[i++] == '\n')
			break;
	}

	line = malloc(sizeof(char) * i);
	if (!line)
		return (line);
	ft_memcpy(line, buf, i);
	return (line);
}
