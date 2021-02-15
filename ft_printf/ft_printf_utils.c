/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:22:30 by seonchoi          #+#    #+#             */
/*   Updated: 2021/02/05 16:51:02 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->zero = 0;
	info->minus = 0;
	info->width = 0;
	info->prec = 0;
	info->prec_width = 0;
	info->type = '\0';
	info->base = 10;
	info->sign = 1;
}

char	*select_base(char c)
{
	if (c == 'x' || c == 'p')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	else
		return ("0123456789");
}
