/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:26:09 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/06 16:49:47 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	valid_alpha_char(char *str)
{
	if (*str >= 'a' && *str <= 'z')
		return (1);
	else if (*str >= 'A' && *str <= 'Z')
		return (2);
	else if (*str >= '0' && *str <= '9')
		return (3);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (valid_alpha_char(str) == 1)
		*str -= 32;
	while (*(str + i))
	{
		if (valid_alpha_char(str + i) == 1)
		{
			if (valid_alpha_char(str + i - 1) == 0)
				*(str + i) -= 32;
		}
		else if (valid_alpha_char(str + i) == 2)
		{
			if (valid_alpha_char(str + i - 1) != 0)
				*(str + i) += 32;
		}
		i++;
	}
	return (str);
}
