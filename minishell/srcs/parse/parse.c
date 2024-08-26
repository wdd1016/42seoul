/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 02:21:08 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/26 23:40:19 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_commands(t_data *data)
{
	tokenize(data);
	data->token.temp = data->token.head;
	if (data->token.temp)
		data->parse_tree = build_tree(data);
}
