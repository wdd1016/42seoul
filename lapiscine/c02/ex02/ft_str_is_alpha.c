/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:43:09 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/06 16:56:16 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		return (1);
	while (*(str + i))
	{
		if (*(str + i) < 'A' || *(str + i) > 'z')
			return (0);
		else if (*(str + i) > 'Z' && *(str + i) < 'a')
			return (0);
		i++;
	}
	return (1);
}
