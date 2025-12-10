/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 08:37:25 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/10 09:09:13by mkhoubaz         ###   ########.fr       */
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
	static int		x;
	static int		z;
	static char		*buf;
	char			*line;

	if (!x)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		read(fd, buf, BUFFER_SIZE);
		x = 1;
	}
	while (i < BUFFER_SIZE)
	{
		if (buf[i++] == '\n' || buf[i] == '\0')
			break ;
	}
	line = malloc(sizeof(char) * (i-z));
	if (!line)
		return (line);
	ft_memcpy(line, buf+z, i-z);
	z = i;
	return (line);
}
