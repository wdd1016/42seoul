#include "ft_printf.h"

int	ft_write_char(va_list ap, t_para *para, int *print_count)
{
	char	c;

	c = va_arg(ap, char);
	if (para->width > 1)
	{
		if ((para->flag & 1) == 1)
			if (write(1, &c, 1) < 0)
				return (-1);
		while (para->width > 1)
		{
			if (write(1, " ", 1) < 0)
				return (-1);
			(*print_count)++;
			(para->width)--;
		}
		if ((para->flag & 1) == 0)
			if (write(1, &c, 1) < 0)
				return (-1);
		(*print_count)++;
	}
	else
		if (write(1, &c, 1) < 0)
			return (-1);
	(*print_count)++;
	return (1);
}

int	ft_write_string(va_list ap, t_para *para, int *print_count)
{
	char	*str;
	size_t	len;

	str = va_arg(ap, char *);
	len = ft_strlen(str);

}

int	ft_write_int(va_list ap, t_para *para, int *print_count)
{
}

int	ft_write_unsigned(va_list ap, t_para *para, int *print_count)
{
}

int	ft_write_ptr(va_list ap, t_para *para, int *print_count)
{
}
