/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:22:23 by seonchoi          #+#    #+#             */
/*   Updated: 2021/02/22 19:45:21 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_all(va_list ap, t_info *info)
{
	int	n;

	n = 0;
	if ((info->minus || (info->prec && info->prec_width >= 0))
		&& info->type != '%')
		info->zero = 0;
	if (info->type == 'c')
		n = print_char(va_arg(ap, int), info);
	else if (info->type == '%')
		n = print_char('%', info);
	else if (info->type == 's')
		n = print_str(va_arg(ap, char *), info);
	else if (info->type == 'd' || info->type == 'i')
		n = print_num(va_arg(ap, int), info);
	else if (info->type == 'x' || info->type == 'X' || info->type == 'u')
		n = print_num(va_arg(ap, unsigned int), info);
	else if (info->type == 'p')
		n = print_num(va_arg(ap, long long), info);
	return (n);
}

void	check_val(va_list ap, char c, t_info *info)
{
	if (ft_isdigit(c))
	{
		if (info->prec == 0)
			info->width = info->width * 10 + (c - 48);
		else
			info->prec_width = info->prec_width * 10 + (c - 48);
	}
	else
	{
		if (info->prec == 0)
		{
			info->width = va_arg(ap, int);
			if (info->width < 0)
			{
				info->minus = 1;
				info->width *= -1;
			}
		}
		else
			info->prec_width = va_arg(ap, int);
	}
}

void	change_info(va_list ap, char c, t_info *info)
{
	if (c == '0')
		info->zero = 1;
	else if (c == '-')
		info->minus = 1;
	else if (c == '.')
		info->prec = 1;
	else if (ft_isdigit(c) || c == '*')
		check_val(ap, c, info);
}

int		parse_string(va_list ap, const char *string, t_info *info)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (string[i] != '\0')
	{
		while (string[i] != '%' && string[i] != '\0')
			n += ft_putchar_fd(string[i++], 1);
		if (string[i] == '%')
		{
			init_info(info);
			while (string[++i] != '\0' && !(ft_strchr(CONVERSIONS, string[i])))
				change_info(ap, string[i], info);
			info->type = string[i++];
			n += print_all(ap, info);
		}
	}
	return (n);
}

int		ft_printf(const char *string, ...)
{
	int		ret;
	t_info	*info;
	va_list	ap;

	if (!(info = (t_info *)malloc(sizeof(t_info) * 1)))
		return (-1);
	va_start(ap, string);
	ret = parse_string(ap, string, info);
	va_end(ap);
	free(info);
	return (ret);
}
