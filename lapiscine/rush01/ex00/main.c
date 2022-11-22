/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:57:17 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/09 08:47:03 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	ft_recursion(int *str_in, int *str_out, int order, int i);

void	input_str(char *str, int *str_in)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(str + i) != '\0')
	{
		if (i % 2 == 0 && *(str + i) >= '1' && *(str + i) <= '4')
		{
			*(str_in + j) = *(str + i) - '0';
			j++;
		}
		else if
			(i % 2 == 1 && *(str + i) == ' ');
		else
			break ;
		i++;
	}
	if (i != 32 - 1 || j != 16)
	{
		write(1, "Error\n", 6);
		*str_in = 0;
	}
}

void	start(char *str)
{
	int	str_in[16];
	int	str_out[16];
	int	i;
	int	success;

	input_str(str, str_in);
	if (*str_in > 0)
	{
		i = 0;
		while (i < 16)
		{
			*(str_out + i) = 0;
			i++;
		}
		ft_recursion(str_in, str_out, 0, 0);
		success = 777;
		if (*str_in != success)
			write(1, "Error\n", 6);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		start(argv[1]);
	else
		write(1, "Error\n", 6);
	return (0);
}
