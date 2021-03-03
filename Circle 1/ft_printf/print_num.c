/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:22:39 by seonchoi          #+#    #+#             */
/*   Updated: 2021/02/05 19:23:55 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_len(long long num, t_info *info)
{
	int	len;

	if (num == 0 && (info->prec == 0 || info->prec_width))
		return (1);
	len = 0;
	while (num)
	{
		num /= info->base;
		len++;
	}
	return (len);
}

void	put_minus(char **n_buf, t_info *info)
{
	if (info->zero == 0 && info->sign == -1)
		*n_buf = ft_strjoin("-", *n_buf);
}

void	put_minus_zero(int buf_len, char **n_buf, t_info *info)
{
	if (info->sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
			*n_buf = ft_strjoin("-", *n_buf);
		else
			*n_buf[0] = '-';
	}
}

void	put_nbr_base(long long num, char **n_buf, t_info *info)
{
	size_t	n;
	int		i;
	int		n_len;

	n_len = num_len(num, info);
	n = (info->prec_width > n_len) ? info->prec_width : n_len;
	if (!(*n_buf = (char *)malloc(sizeof(char) * n + 1)))
		return ;
	(*n_buf)[n] = '\0';
	i = 0;
	while (n_len + i < (int)n)
		(*n_buf)[i++] = '0';
	if (num == 0 && (info->prec == 0 || info->prec_width))
		(*n_buf)[n - 1] = '0';
	i = 1;
	while (num)
	{
		(*n_buf)[n - i++] = select_base(info->type)[num % info->base];
		num /= info->base;
	}
}

int		print_num(long long num, t_info *info)
{
	int		n;
	int		buf_len;
	char	*n_buf;

	n = 0;
	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->base = 16;
	else if (num < 0)
	{
		info->sign = -1;
		num *= -1;
	}
	put_nbr_base(num, &n_buf, info);
	put_minus(&n_buf, info);
	if (info->type == 'p')
		n_buf = ft_strjoin("0x", n_buf);
	buf_len = (int)ft_strlen(n_buf);
	check_width(&n_buf, info);
	put_minus_zero(buf_len, &n_buf, info);
	n = ft_putstr_fd(n_buf, 1);
	free(n_buf);
	return (n);
}
