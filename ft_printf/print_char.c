/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:22:34 by seonchoi          #+#    #+#             */
/*   Updated: 2021/02/05 16:51:00 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_zero(int len)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i++ < len)
		n += ft_putchar_fd('0', 1);
	return (n);
}

int	put_space(int len)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i++ < len)
		n += ft_putchar_fd(' ', 1);
	return (n);
}

int	print_char(int c, t_info *info)
{
	int	n;

	n = 0;
	if (info->width >= 1)
		info->width -= 1;
	if (info->minus == 1)
	{
		n += ft_putchar_fd(c, 1);
		info->zero = 0;
	}
	if (info->zero == 1)
		n += put_zero(info->width);
	else
		n += put_space(info->width);
	if (info->minus == 0)
		n += ft_putchar_fd(c, 1);
	return (n);
}
