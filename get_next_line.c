/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:09:15 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/17 13:06:10 by mkhoubaz         ###   ########.fr       */
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
	static int		i;
	static int		flag;
	static char		*buf;
	char			*line;
	int				sline;

	if (!flag)
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	initialize(&flag, &sline);
	if (BUFFER_SIZE == 0)
		return (NULL);
	while (1)
	{
		read(fd, buf + i, 1);
		sline++;
		if (buf[i++] == '\n')
			break ;
	}
	line = ft_memcpy(malloc(sizeof(char) * sline), buf + (i - sline), sline);
	return (line);
}

// tets