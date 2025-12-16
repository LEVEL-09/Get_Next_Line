/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhoubaz <mkhoubaz@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:32:17 by mkhoubaz          #+#    #+#             */
/*   Updated: 2025/12/09 15:45:13 by mkhoubaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
static char		*ft_strdup(const char *s);
static size_t	ft_strlen(const char *s);
static void		*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2, int index);

#endif