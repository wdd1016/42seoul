/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:37:59 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/19 11:52:17 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_sort_string_tab(char **tab)
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
			if (ft_compare_string(tab[j], tab[j + 1]) > 0)
				ft_swap_point(tab, j, j + 1);
			j++;
		}
		i--;
	}
}
