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

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(const char *s)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	ft_memcpy(p, s, ft_strlen(s) + 1);
	return (p);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, ft_strlen(s1));
	ft_memcpy(ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (ptr);
}

#include <stdio.h>
char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	char		*temp;
	int			flag;
	int			i;
	int			len_buf;

	flag = 0;
	while (!flag)
	{
		i = 0;
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		len_buf = read(fd, buf, BUFFER_SIZE);
		while (i < BUFFER_SIZE)
		{
			if (buf[i++] == '\n')
			{
				flag = 1;
				break ;
			}
		}
		temp = ft_strdup(line);
		free(line);
		line = ft_strjoin(temp, buf);
		free(buf);
	}
	free(temp);
	return(line);
}

// Why when i use free i have carbage value
// How i can know size i need alloc for line 