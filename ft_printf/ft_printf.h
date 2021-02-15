/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonchoi <seonchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 20:26:14 by seonchoi          #+#    #+#             */
/*   Updated: 2021/02/05 14:11:06 by seonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define CONVERSIONS "csdiupxX%"

typedef struct	s_info
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	int			prec_width;
	char		type;
	int			base;
	int			sign;
}				t_info;

void			init_info(t_info *info);
char			*select_base(char c);

int				put_zero(int len);
int				put_space(int len);
int				print_char(int c, t_info *info);

int				num_len(long long num, t_info *info);
void			put_minus(char **n_buf, t_info *info);
void			put_minus_zero(int buf_len, char **n_buf, t_info *info);
void			put_nbr_base(long long num, char **n_buf, t_info *info);
int				print_num(long long num, t_info *info);

void			check_width(char **n_buf, t_info *info);
int				print_str(char *str, t_info *info);

int				print_all(va_list ap, t_info *info);
void			check_val(va_list ap, char c, t_info *info);
void			change_info(va_list ap, char c, t_info *info);
int				parse_string(va_list ap, const char *string, t_info *info);
int				ft_printf(const char *string, ...);

#endif
