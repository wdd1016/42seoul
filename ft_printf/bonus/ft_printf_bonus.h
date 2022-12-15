/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:07:41 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/12 21:37:43 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

# define FLAG_MINUS 1
# define FLAG_ZERO 2
# define FLAG_SHARP 4
# define FLAG_SPACE 8
# define FLAG_PLUS 16
# define P_OFF 0
# define P_ON 1
# define P_OVERFLOW 2

int	ft_make_struct(const char **str, t_para *para);
int	ft_write_char(va_list ap, t_para *para, int *print_count);
int	ft_write_string(va_list ap, t_para *para, int *print_count);
int	ft_write_int(va_list ap, t_para *para, int *print_count);
int	ft_write_unsigned(va_list ap, t_para *para, int *print_count);
int	ft_write_16base_us_int_small(va_list ap, t_para *para, \
int *print_count);
int	ft_write_16base_us_int_big(va_list ap, t_para *para, int *print_count);
int	ft_write_ptr(va_list ap, t_para *para, int *print_count);

#endif