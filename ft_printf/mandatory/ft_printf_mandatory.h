/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mandatory.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:07:41 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/16 01:04:41 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_MANDATORY_H
# define FT_PRINTF_MANDATORY_H

# include "../ft_printf.h"

int	ft_write_char(va_list ap, int *print_count);
int	ft_write_string(va_list ap, int *print_count);
int	ft_write_int(va_list ap, int *print_count, t_para *para);
int	ft_write_16base(va_list ap, int *print_count, t_para *para);
int	ft_write_ptr(va_list ap, int *print_count, t_para *para);

#endif