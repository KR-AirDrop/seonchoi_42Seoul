/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 12:45:48 by seonchoi          #+#    #+#             */
/*   Updated: 2021/01/23 14:28:59 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

static	int		check_over_range(unsigned long long nbr, int sign)
{
	if (nbr > LLONG_MAX - 1 && sign == -1)
		return (0);
	if (nbr > LLONG_MAX && sign == 1)
		return (-1);
	return (nbr);
}

int				ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long		nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str[i])
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	nbr = check_over_range(nbr, sign);
	return (nbr * sign);
}
