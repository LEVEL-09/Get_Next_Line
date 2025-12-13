/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:09:15 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/11 15:10:14 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	if (!dest || !src)
		return (NULL);
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

static void	initialize(int *flag, int *size_line)
{
	*flag = 1;
	*size_line = 0;
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	size;
	int			i;
	int			flag;
	char		*line;

	i = size;
	flag = 0;
	while (!flag)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + size + 1));
		size += read(fd, buf+size, BUFFER_SIZE);
		while (i < size)
		{
			if (buf[i++] == '\n')
			{
				flag = size - i; 
				// leonax\nddddd | bufsize=4
				// i = 4; size = 8; 4 < 8; 
				// i = 7; 
				break ;
			}
		}
	}
	ft_memcpy(malloc(sizeof(char) * i), buf + flag, i);
	return (line);
}
