/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:07:41 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/23 23:49:25 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_para
{
	char	flag;
	int		width;
	int		precision;
	char	format;

}	t_para;

int	ft_printf(const char *str, ...);
int	ft_process_print(va_list ap, const char *str, t_para *para, int *p_count);
int	ft_make_struct(const char *str, t_para *para, int *len_count);
int	ft_write_char(va_list ap, t_para *para, int *print_count);
int	ft_write_string(va_list ap, t_para *para, int *print_count);
int	ft_write_int(va_list ap, t_para *para, int *print_count);
int	ft_write_unsigned(va_list ap, t_para *para, int *print_count);
int	ft_write_ptr(va_list ap, t_para *para, int *print_count);

#endif