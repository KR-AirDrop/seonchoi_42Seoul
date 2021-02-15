/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:22:43 by seonchoi          #+#    #+#             */
/*   Updated: 2021/02/05 16:51:01 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(char **buf, t_info *info)
{
	int		i;
	size_t	len;
	char	*width;

	len = ft_strlen(*buf);
	if (info->width <= (int)len)
		return ;
	if (!(width = (char *)malloc(sizeof(char) * (info->width - len + 1))))
		return ;
	i = -1;
	while (++i < info->width - (int)len)
		width[i] = (info->zero) ? '0' : ' ';
	width[i] = '\0';
	if (info->minus)
		*buf = ft_strjoin(*buf, width);
	else
		*buf = ft_strjoin(width, *buf);
	free(width);
}

int		print_str(char *str, t_info *info)
{
	int		n;
	size_t	len;
	size_t	p_width;
	char	*s_buf;

	n = 0;
	p_width = info->prec_width;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (info->prec && p_width < len)
		len = p_width;
	if (!(s_buf = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_strlcpy(s_buf, str, len + 1);
	check_width(&s_buf, info);
	n = ft_putstr_fd(s_buf, 1);
	free(s_buf);
	return (n);
}
