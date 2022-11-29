/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:07:41 by juyojeon          #+#    #+#             */
/*   Updated: 2022/11/29 00:58:47 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_para
{
	int		flag;
	int		width;
	int		precision;
	int		format;

}	t_para;

char	*ft_strchr(const char *s, int c);

int		ft_printf(const char *str, ...);
int		ft_write_str_count(const char *str, int *count);
int		ft_process_print(va_list ap, const char **str, t_para *para, \
int *p_count);
int		ft_make_struct(const char **str, t_para *para);
int		ft_write_char(va_list ap, t_para *para, int *print_count);
int		ft_write_string(va_list ap, t_para *para, int *print_count);
int		ft_write_int(va_list ap, t_para *para, int *print_count);
int		ft_write_unsigned(va_list ap, t_para *para, int *print_count);
int		ft_write_ptr(va_list ap, t_para *para, int *print_count);

#endif