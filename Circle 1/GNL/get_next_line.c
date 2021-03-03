/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 02:40:56 by seonchoi          #+#    #+#             */
/*   Updated: 2021/03/03 12:51:44 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define OPEN_MAX 1024

int		is_newline(char *str)   // 문자열에 개행이 있으면 해당 인덱스, 없으면 -1 반환
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	split_backup(char *backup, int split_idx, char *tmp)   // backup을 자르고, 앞부분 반환, backup을 뒤에 부분으로 재설정
{
	backup[split_idx] = '\0';
	tmp = ft_strdup(backup);
	free(backup);
	backup = tmp + split_idx + 1;
}

int		normal_return(char **line, char **backup, int split_idx) // backup을 개행기준으로 자르고, 저장, 1 또는 0 반환. (line도 변경)
{
	char *tmp;

	split_backup(*backup, split_idx, tmp);
	*line = tmp;
	return (1);
}

int		final_return(char **line, char **backup)
{
	char *tmp;
	int split_idx;

	if (split_idx = is_newline(*backup) >= 0)
	{
		split_backup(*backup, split_idx, tmp);
		return (1);
	}
	else
	{
		*line = *backup;
		*backup = NULL;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *backup[OPEN_MAX];
	char		*buf;
	int			r_size;
	int			split_idx;

	if (BUFFER_SIZE < 1 || fd < 0 || line == 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((r_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		if ((split_idx = is_newline(backup[fd])) >= 0)
			return (normal_return(line, &backup[fd], split_idx));
	}
	return (final_return(line, &backup[fd]));
}
