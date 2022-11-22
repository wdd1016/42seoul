/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:01:11 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/19 15:24:36 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	ft_atoi(char *str);
extern void	ft_putnbr(int nb);
extern int	sum(int x, int y);
extern int	sub(int x, int y);
extern int	div(int x, int y);
extern int	mul(int x, int y);
extern int	rem(int x, int y);

int	ft_valid_num_operator(char *oper)
{
	if (oper[1] == '\0')
	{
		if (oper[0] == '+')
			return (0);
		if (oper[0] == '-')
			return (1);
		if (oper[0] == '/')
			return (2);
		if (oper[0] == '*')
			return (3);
		if (oper[0] == '%')
			return (4);
	}
	return (-1);
}

int	ft_is_valid_calculation(char *argv[])
{
	if (ft_atoi(argv[3]) == 0)
	{
		if (*argv[2] == '/' || *argv[2] == '%')
			return (0);
	}
	return (1);
}

void	ft_caluation_and_write(char *argv[])
{
	int	(*ft[5])(int, int);
	int	result;
	int	n;

	ft[0] = sum;
	ft[1] = sub;
	ft[2] = div;
	ft[3] = mul;
	ft[4] = rem;
	n = ft_valid_num_operator(argv[2]);
	result = ft[n](ft_atoi(argv[1]), ft_atoi(argv[3]));
	ft_putnbr(result);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
	{
		if (ft_valid_num_operator(argv[2]) == -1)
		{
			write(1, "0\n", 2);
			return (0);
		}
		else if (ft_is_valid_calculation(argv) == 0)
		{
			if (*argv[2] == '/')
				write(1, "Stop : division by zero\n", 24);
			else if (*argv[2] == '%')
				write(1, "Stop : modulo by zero\n", 22);
			return (0);
		}
		else
		{
			ft_caluation_and_write(argv);
			return (0);
		}
	}
	else
		return (0);
}
