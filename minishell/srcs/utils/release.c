/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:51:07 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/21 21:09:52 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_data *data)
{
	t_tokennode	*token;
	t_tokennode	*next;

	token = data->token.head;
	while (token)
	{
		next = token->next;
		free(token->parsed_data);
		free(token);
		token = next;
	}
	data->token.tail = NULL;
}
