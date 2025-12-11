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
	static int		i;
	static int		x;
	static int		flag;
	static char		*buf;
	char			*line;
	int 			size_line;

	if (!flag)
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	initailiza(&flag, &size_line);
	if (BUFFER_SIZE == 0)
		return (NULL);
	while (1)
	{
		read(fd, buf+i, 1);
		size_line++;
		if (buf[i++] == '\n')
			break ;
	}
	line = ft_memcpy(malloc(sizeof(char) * size_line), buf+x, size_line);
	x = i;
	return (line);
}
