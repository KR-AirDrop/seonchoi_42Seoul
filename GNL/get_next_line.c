/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 02:40:56 by seonchoi          #+#    #+#             */
/*   Updated: 2021/02/15 19:28:18 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_is_newline(char *str)   // 문자열에 개행이 있으면 1, 없으면 0 반환
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		not_read(char **line, char *backup, char *buf)
{

}

int		read_str(char **line, char *backup, char *buf)
{

}

int		get_next_line(int fd, char **line)
{
	static char *backup;
	char		*buf;
	int			ret;

	if (BUFFER_SIZE < 1 || fd < 0 || line == 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[ret] = '\0';
		if (ret == 0)
			return (not_read(line, &(backup), &buf)); // 읽어온게 없을 때 반환 (0)
		else if (0 < ret && ret <= BUFFER_SIZE)
		{
			ret = read_str(line, &(backup), &buf);	// 읽어온게 있을 때. 
			if (ret == REMAIN)
				continue;
			return (ret);
		}
	}
	return (-1);
}