/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:23:47 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 00:31:44 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_convert_to_c(char *str, int nbr, int nbr_len)
{
	int			nbr_idx;
	const char	*base = "0123456789";

	nbr_idx = nbr_len - 1;
	if (nbr < 0)
	{
		while (nbr != 0)
		{
			str[nbr_idx] = base[-(nbr % 10)];
			nbr_idx--;
			nbr /= 10;
		}
	}
	else if (nbr > 0)
	{
		while (nbr != 0)
		{
			str[nbr_idx] = base[nbr % 10];
			nbr_idx--;
			nbr /= 10;
		}
	}
	else
		str[0] = '0';
}

char	*ft_itoa(int n)
{
	char	*str_int;
	int		nbr_len;
	int		tmp;

	tmp = n;
	nbr_len = 0;
	if (tmp <= 0)
		nbr_len++;
	while (tmp)
	{
		tmp /= 10;
		nbr_len++;
	}	
	str_int = (char *)malloc_s(sizeof(char) * (nbr_len + 1));
	str_int[nbr_len] = '\0';
	ft_convert_to_c(str_int, n, nbr_len);
	if (n < 0)
		*str_int = '-';
	return (str_int);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*temp;

	str = (char *)malloc_s(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	temp = str;
	if (s1)
		while (*s1)
			*temp++ = *s1++;
	if (s2)
		while (*s2)
			*temp++ = *s2++;
	*temp = '\0';
	return (str);
}

char	*generate_random_heredoc_filepath(int length)
{
    const char	*charset[] = \
	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int	charsetSize = 62;
	const char	*prefix = "/tmp/.minishell";
	const int	prefixSize = 15;
	char		*str;
	int			i;

	str = (char *)malloc_s(sizeof(char) * (prefixSize + length + 1));
	i = 0;
	while (i < prefixSize)
	{
		str[i] = prefix[i];
		i++;
	}
	while (i < prefixSize + length)
	{
		int randomIndex = rand() % charsetSize;
		str[i] = charset[randomIndex];
		i++;
	}
	str[length] = '\0';
	return (str);
}
