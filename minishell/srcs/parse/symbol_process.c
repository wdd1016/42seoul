/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:30:11 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/26 23:21:59 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	quote_erase_expansion(t_data *dt, char **str_ptr);
static void	quote_erase(char **str_ptr, size_t start, size_t end);

size_t	quote(t_data *data, char *string, char character, size_t end)
{
	end++;
	while (string[end] && string[end] != character)
		end++;
	if (string[end] == character)
		end++;
	else
	{
		if (character == '\'')
			parse_error(data, "single quote");
		else
			parse_error(data, "double quote");
	}
	return (end);
}

void	command_symbol_process(t_data *data, t_tokennode *temp)
{
	size_t	i;

	i = 0;
	while (temp->parsed_data[i])
	{
		if (temp->parsed_data[i] == '\'')
			i = quote(data, temp->parsed_data, '\'', i);
		else if (temp->parsed_data[i] == '\"')
			i = quote(data, temp->parsed_data, '\"', i);
		else if (temp->parsed_data[i] == '$' && \
		temp->parsed_data[i + 1] != ' ' && temp->parsed_data[i + 1] != '\0')
			i = expansion(data->env_list, &(temp->parsed_data), i + 1, \
						ft_substr(temp->parsed_data, 0, i));
		else
			i++;
	}
	temp->cmd = ft_split(temp->parsed_data, ' ');
	i = 0;
	while (temp->cmd[i])
	{
		quote_erase_expansion(data, &(temp->cmd[i]));
		i++;
	}
}

void	file_symbol_process(t_data *data, t_tokennode *temp)
{
	size_t		i;

	i = 0;
	while (temp->parsed_data[i])
	{
		if (temp->parsed_data[i] == '\'')
			i = quote(data, temp->parsed_data, '\'', i);
		else if (temp->parsed_data[i] == '\"')
			i = quote(data, temp->parsed_data, '\"', i);
		else if (temp->parsed_data[i] == '$' && \
		temp->parsed_data[i + 1] != ' ' && temp->parsed_data[i + 1] != '\0')
			i = expansion(data->env_list, &(temp->parsed_data), i + 1, \
						ft_substr(temp->parsed_data, 0, i));
		else
			i++;
	}
	quote_erase_expansion(data, &(temp->parsed_data));
}

static void	quote_erase_expansion(t_data *dt, char **str_ptr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((*str_ptr)[i])
	{
		if ((*str_ptr)[i] == '\'')
			quote_erase(str_ptr, i, quote(dt, *str_ptr, '\'', i) - 1);
		else if ((*str_ptr)[i] == '\"')
		{
			j = i;
			while ((*str_ptr)[++i] != '\"')
				if ((*str_ptr)[i] == '$' && (*str_ptr)[i + 1] != ' ' && \
					(*str_ptr)[i + 1] != '\0')
					i = expansion(dt->env_list, str_ptr, i + 1, \
								ft_substr(*str_ptr, 0, i));
			quote_erase(str_ptr, j, quote(dt, *str_ptr, '\"', j) - 1);
		}
		else
			i++;
	}
}

static void	quote_erase(char **str_ptr, size_t start, size_t end)
{
	char	*new_data;
	size_t	i;

	new_data = (char *)malloc_s(sizeof(char) * (ft_strlen(*str_ptr) - 1));
	i = -1;
	while (++i < start)
		new_data[i] = (*str_ptr)[i];
	while (++i < end)
		new_data[i - 1] = (*str_ptr)[i];
	while ((*str_ptr)[++i])
		new_data[i - 2] = (*str_ptr)[i];
	new_data[i - 2] = '\0';
	free(*str_ptr);
	*str_ptr = new_data;
}