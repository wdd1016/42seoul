/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:07:41 by juyojeon          #+#    #+#             */
/*   Updated: 2022/12/07 00:01:31 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_para
{
	int				flag;
	unsigned int	width;
	int				precision;
	int				format;

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

#endif