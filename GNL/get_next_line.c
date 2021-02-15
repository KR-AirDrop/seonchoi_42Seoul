/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 02:40:56 by seonchoi          #+#    #+#             */
/*   Updated: 2021/02/15 20:21:44 by seonchoi         ###   ########.fr       */
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

void	ft_split_backup(char **line, char *backup)
{
	int		i;
	char	*tmp;

	i = 0;
	while (backup[i] != '\n')
		i++;
	backup[i] = '\0';
	*line = ft_strdup(backup);
	tmp = ft_strdup(backup + i + 1);
	free(backup);
	backup = ft_strdup(tmp);  // 잘 안되네...
}

int		not_read(char **line, char **backup)
{
	if (ft_is_newline(backup))
	{
		ft_split_backup(line, backup);
		return (1);
	}
	else
		return (0);
}

int		read_str(char **line, char *backup, char *buf)
{
	if (backup == NULL)
		backup = ft_strdup(buf);
	else
		backup = ft_strjoin(backup, buf);
	
	if (ft_is_newline(backup))
	{
		ft_split_backup(line, backup);
		return (1);
	}
	else
		return (REMAIN);
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
			return (not_read(line, backup));
		else if (0 < ret && ret <= BUFFER_SIZE)
		{
			ret = read_str(line, backup, buf);
			if (ret == REMAIN)
				continue;
			return (ret);
		}
	}
	return (-1);
}