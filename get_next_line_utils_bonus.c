/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:13:50 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/23 18:12:05 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*subs(char **line, char **buf)
{
	*buf = ft_substr(*line);
	*line = ft_subjoin(*line);
	return (*buf);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *s)
{
	char	*p;

	p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!p)
		return (free(s), NULL);
	ft_strncpy(p, s, ft_strlen(s) + 1);
	free(s);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (free(s1), free(s2), NULL);
	ft_strncpy(ptr, s1, ft_strlen(s1));
	ft_strncpy(ptr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	free(s2);
	return (ptr);
}
