/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:46:04 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/16 22:58:46 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap_point(char *str[], int i, int j)
{
	char	*str_temp;

	str_temp = str[i];
	str[i] = str[j];
	str[j] = str_temp;
}

int	ft_compare_string(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	return ((int)*str1 - (int)*str2);
}

void	ft_sort_strings(int argc, char *argv[])
{
	int	i;
	int	j;

	i = argc - 1;
	while (i > 1)
	{
		j = 1;
		while (j < i)
		{
			if (ft_compare_string(argv[j], argv[j + 1]) > 0)
				ft_swap_point(argv, j, j + 1);
			j++;
		}
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc > 2)
		ft_sort_strings(argc, argv);
	i = 0;
	while (++i < argc)
	{
		while (*argv[i])
		{
			write(1, argv[i], 1);
			(argv[i])++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
