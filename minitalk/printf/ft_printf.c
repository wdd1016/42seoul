/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 23:20:35 by juyojeon          #+#    #+#             */
/*   Updated: 2023/01/29 02:27:43 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_print(va_list ap, const char **str, t_para *para, \
int *p_count);
static int	ft_print_format(va_list ap, t_para *para, int *print_count);
static void	*ft_memset(void *b, int c, size_t len);

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_para	parameter;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_process_print(ap, &str, &parameter, &count) == -1)
				return (-1);
		}
		else
		{
			if (write(1, str, 1) < 0)
				return (-1);
			count++;
			str++;
		}
	}
	va_end(ap);
	return (count);
}

static int	ft_process_print(va_list ap, const char **str, t_para *para, \
int *p_count)
{
	if (**str == '\0')
		return (0);
	ft_memset(para, 0, sizeof(t_para));
	para->format = **str;
	(*str)++;
	if (ft_print_format(ap, para, p_count) == -1)
		return (-1);
	return (1);
}

static int	ft_print_format(va_list ap, t_para *para, int *print_count)
{
	int	i;

	i = 0;
	if (para->format == 'c')
		i = ft_write_char(ap, print_count);
	else if (para->format == 's')
		i = ft_write_string(ap, print_count);
	else if (para->format == 'd' || para->format == 'i' || para->format == 'u')
		i = ft_write_int(ap, print_count, para);
	else if (para->format == 'x' || para->format == 'X')
		i = ft_write_16base(ap, print_count, para);
	else if (para->format == 'p')
		i = ft_write_ptr(ap, print_count, para);
	else if (para->format == '%')
	{
		if (write(1, "%", 1) < 0)
			return (-1);
		(*print_count)++;
	}
	return (i);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;
	unsigned char	uch_c;
	size_t			i;

	i = 0;
	uch_c = (unsigned char)c;
	temp_b = (unsigned char *)b;
	while (i < len)
	{
		temp_b[i] = uch_c;
		i++;
	}
	return (b);
}
