/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:26:17 by juyojeon          #+#    #+#             */
/*   Updated: 2022/10/18 23:18:37 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char ch, char *charset)
{
	while (*charset)
	{
		if (ch == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_count_words(char *str_prev, char *charset)
{
	int	word_count;
	int	flag_in_string;
	int	i;

	word_count = 0;
	flag_in_string = 0;
	i = 0;
	while (str_prev[i])
	{
		if (ft_is_sep(str_prev[i], charset) == 0 && flag_in_string == 0)
		{
			flag_in_string = 1;
			word_count++;
		}
		if (ft_is_sep(str_prev[i], charset) == 1)
			flag_in_string = 0;
		i++;
	}
	return (word_count);
}

int	ft_malloc_strings(char *str_p, char **str_spt, char *charset, int word_cnt)
{
	int	flag_in_string;
	int	i;
	int	j;

	flag_in_string = 0;
	i = 0;
	while (str_p[i])
	{
		if (ft_is_sep(str_p[i], charset) == 0 && flag_in_string == 0)
		{
			flag_in_string = 1;
			word_cnt++;
			j = 0;
			while (ft_is_sep(str_p[i + j], charset) == 0 && str_p[i + j])
				j++;
			str_spt[word_cnt] = (char *)malloc(sizeof(char) * (j + 1));
			if (str_spt[word_cnt] == 0)
				return (0);
			i += j - 1;
		}
		if (ft_is_sep(str_p[i], charset) == 1)
			flag_in_string = 0;
		i++;
	}
	return (1);
}

void	ft_insert_words(char *str_p, char **str_spt, char *cet, int word_cnt)
{
	int	flag_in_string;
	int	i;
	int	j;

	flag_in_string = 0;
	i = 0;
	while (str_p[i])
	{
		if (ft_is_sep(str_p[i], cet) == 0 && flag_in_string == 0)
		{
			flag_in_string = 1;
			word_cnt++;
			j = 0;
			while (ft_is_sep(str_p[i + j], cet) == 0 && str_p[i + j])
			{
				*(str_spt[word_cnt] + j) = str_p[i + j];
				j++;
			}
			*(str_spt[word_cnt] + j) = '\0';
			i += j - 1;
		}
		if (ft_is_sep(str_p[i], cet) == 1)
			flag_in_string = 0;
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**str_spt;
	int		word_count;

	word_count = ft_count_words(str, charset);
	str_spt = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (str_spt == 0)
		return (0);
	if (ft_malloc_strings(str, str_spt, charset, -1) == 0)
		return (0);
	ft_insert_words(str, str_spt, charset, -1);
	str_spt[word_count] = 0;
	return (str_spt);
}
