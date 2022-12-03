/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:07:41 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/04 00:01:13 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_para
{
	int					flag;
	unsigned long long	width;
	unsigned long long	precision;
	int					format;

}	t_para;

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_itoa(int n, int *print_count);
int		ft_utoa(unsigned int n, int *print_count);
int		ft_utosx(unsigned int n, int *print_count);
int		ft_utobx(unsigned int n, int *print_count);
int		ft_ulltox(size_t n, int *print_count);

int		ft_printf(const char *str, ...);
int		ft_process_print(va_list ap, const char **str, \
t_para *para, int *p_count);
void	ft_make_struct(const char **str, t_para *para);
int		ft_write_char(va_list ap, int *print_count);
int		ft_write_string(va_list ap, int *print_count);
int		ft_write_int(va_list ap, int *print_count);
int		ft_write_unsigned(va_list ap, int *print_count);
int		ft_write_16base_us_int_small(va_list ap, int *print_count);
int		ft_write_16base_us_int_big(va_list ap, int *print_count);
int		ft_write_ptr(va_list ap, int *print_count);

#endif