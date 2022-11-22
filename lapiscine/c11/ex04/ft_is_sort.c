/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:21:40 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/19 15:47:00 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag_sort_dir;

	i = 0;
	flag_sort_dir = 1;
	while (i < length - 1 && flag_sort_dir == 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
		{
			flag_sort_dir = -1;
			break ;
		}
		i++;
	}
	if (i == length - 1)
		return (1);
	i = 0;
	while (i < length - 1 && flag_sort_dir == -1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}
