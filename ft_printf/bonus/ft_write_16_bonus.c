
#include "ft_printf_bonus.h"

int	ft_write_16base_us_int_small(va_list ap, t_para *para, int *print_count)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	if (ft_utosx(i, print_count) == -1)
		return (-1);
	else
		return (1);
	return (1);
}

int	ft_write_16base_us_int_big(va_list ap, t_para *para, int *print_count)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	if (ft_utobx(i, print_count) == -1)
		return (-1);
	else
		return (1);
	return (1);
}