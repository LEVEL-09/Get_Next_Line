/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:13:55 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/23 09:59:31 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*fill_zero(char **line, char **buf, int flag)
{
	free(*buf);
	if (!(*line) || line[0][0] == '\0' || flag == 1)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	*buf = *line;
	*line = NULL;
	return(*buf);
}

static int	ft_check(char *s, char c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i++] == c)
			return (i);
	}
	if (s[i++] == c)
		return (i);
	return (-1);
}

char	*ft_substr(char *str)
{
	int		i;
	char	*p;

	i = 0;
	if(!str)
		return (NULL);
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

char	*ft_subjoin(char *str)
{
	char	*ptr;
	int		len;
	int		i;

	if (!str)
		return (NULL);
	i = ft_check(str, '\n');
	if (i == -1)
		i = 0;
	len = ft_strlen(str + i);
	ptr = malloc(len + 1);
	if (!ptr)
		return (fill_zero(&str, NULL, 0));
	ptr = ft_strncpy(ptr, str + i, len + 1);
	free(str);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*line[1025];
	char		*buf;
	ssize_t		fill;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	fill = 1;
	while (1)
	{
		buf = malloc((size_t)BUFFER_SIZE + 1);
		if (!buf)
			return (fill_zero(&line[fd], &buf, 0));
		fill = read(fd, buf, BUFFER_SIZE);
		if (fill < 0)
			return (fill_zero(&line[fd], &buf, 1));
		buf[fill] = '\0';
		if (fill == 0 && ft_check(line[fd], '\n') == -1)
			return (fill_zero(&line[fd], &buf, 0));
		line[fd] = ft_strjoin(line[fd], buf);
		if (ft_check(line[fd], '\n') != -1)
			return (subs(&line[fd], &buf));
	}
	return (NULL);
}
