/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:23:47 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/30 03:22:14 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_convert_to_c(char *str, int nbr, int nbr_len);

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

char	*generate_random_heredoc_filepath(int length)
{
	const char	charset[63] = \
	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	const char	*prefix = "/tmp/.minishell";
	char		*str;
	int			i;

	str = (char *)malloc_s(sizeof(char) * (15 + length + 1));
	i = 0;
	while (i < 15)
	{
		str[i] = prefix[i];
		i++;
	}
	while (i < 15 + length)
	{
		str[i] = charset[rand() % 62];
		i++;
	}
	str[length] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*copy;
	char	*temp;

	len = 0;
	while (s1[len])
		len++;
	copy = (char *)malloc_s(sizeof(char) * (len + 1));
	temp = copy;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (copy);
}

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
