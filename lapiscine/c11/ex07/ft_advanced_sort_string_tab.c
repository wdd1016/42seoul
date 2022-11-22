/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:46:17 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/19 11:52:16 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_point(char *str[], int i, int j)
{
	char	*str_temp;

	str_temp = str[i];
	str[i] = str[j];
	str[j] = str_temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	i -= 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap_point(tab, j, j + 1);
			j++;
		}
		i--;
	}
}
