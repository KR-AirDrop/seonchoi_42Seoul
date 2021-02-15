/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 02:41:53 by seonchoi          #+#    #+#             */
/*   Updated: 2021/02/15 20:08:09 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# define REMAIN 42
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t destsize);
//size_t	ft_strlcat(char *dest, char *src, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *str1, char const *str2);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif