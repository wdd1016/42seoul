/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:00:05 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/25 00:00:14 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	build_tree(t_data *data)
{
	t_parsenode	*temp;
	t_tokennode	*token;

	token = data->token.head;
	while (token)
	{
		temp = (t_parsenode *)malloc(sizeof(t_parsenode));
		if (!temp)
			parse_error(data, "malloc failed\n");
		temp->cmd = NULL;
		temp->next = NULL;
		if (token->type == CMD)
			cmd_with_symbol_process(data, token);
		else if (token->type == PIPE)
			temp->type = PIPE;
		else if (token->type == SEMICOLON)
			temp->type = SEMICOLON;
		else if (token->type == REDIRECT)
			temp->type = REDIRECT;
		else if (token->type == END)
			temp->type = END;
		else
			parse_error(data, "invalid token\n");
		if (!data->parse_tree)
			data->parse_tree = temp;
		else
			add_back_parse(&(data->parse_tree), temp);
		token = token->next;
	}
}
