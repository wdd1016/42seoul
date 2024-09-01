/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:16:38 by juyojeon          #+#    #+#             */
/*   Updated: 2024/09/01 19:29:10 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_count_words(const char *str, char sep);
static void		ft_malloc_strings(const char *str, char **s_spt, char sep);
static size_t	check_quote(const char *str, size_t i);

char	**ft_split(const char *str, char sep)
{
	char	**s_spt;
	size_t	word_count;

	if (str == NULLPOINTER)
		return (NULLPOINTER);
	word_count = ft_count_words(str, sep);
	s_spt = (char **)malloc_s(sizeof(char *) * (word_count + 1));
	ft_malloc_strings(str, s_spt, sep);
	s_spt[word_count] = 0;
	return (s_spt);
}

static size_t	ft_count_words(const char *str, char sep)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			word_count++;
			while (str[i] && str[i] != sep)
			{
				if (str[i] == '\"' || str[i] == '\'')
					i = quote(NULLPOINTER, str, str[i], i);
				else
					i++;
			}
		}
		else
			i++;
	}
	return (word_count);
}

static void	ft_malloc_strings(const char *str, char **s_spt, char sep)
{
	size_t	word_count;
	size_t	i;
	size_t	j;

	word_count = 0;
	while (*str)
	{
		if (*str != sep)
		{
			i = 0;
			while (str[i] && str[i] != sep)
				i = check_quote(str, i);
			s_spt[word_count] = (char *)malloc_s(sizeof(char) * (i + 1));
			j = -1;
			while (++j < i)
				*(s_spt[word_count] + j) = str[j];
			*(s_spt[word_count] + j) = '\0';
			word_count++;
			str += i;
		}
		else
			str++;
	}
}

static size_t	check_quote(const char *str, size_t i)
{
	if (str[i] == '\"' || str[i] == '\'')
		return (quote(NULLPOINTER, str, str[i], i));
	else
		return (i + 1);
}
