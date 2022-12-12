/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mandatory.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:07:41 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/12 20:37:13 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_MANDATORY_H
# define FT_PRINTF_MANDATORY_H

# include "ft_printf.h"

int	ft_write_char(va_list ap, int *print_count);
int	ft_write_string(va_list ap, int *print_count);
int	ft_write_int(va_list ap, int *print_count);
int	ft_write_unsigned(va_list ap, int *print_count);
int	ft_write_16base_us_int_small(va_list ap, int *print_count);
int	ft_write_16base_us_int_big(va_list ap, int *print_count);
int	ft_write_ptr(va_list ap, int *print_count);

#endif