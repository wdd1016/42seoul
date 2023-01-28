/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:07:41 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/29 02:36:34 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_para
{
	int	flag;
	int	width;
	int	precision;
	int	pre_state;
	int	format;
}	t_para;

int		ft_printf(const char *str, ...);
int		ft_abstoa(long long n, int *print_count);
int		ft_ulltox(size_t n, int *print_count, t_para *para);
int		ft_write_char(va_list ap, int *print_count);
int		ft_write_string(va_list ap, int *print_count);
int		ft_write_int(va_list ap, int *print_count, t_para *para);
int		ft_write_16base(va_list ap, int *print_count, t_para *para);
int		ft_write_ptr(va_list ap, int *print_count, t_para *para);

#endif