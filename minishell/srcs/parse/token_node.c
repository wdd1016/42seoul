#include "minishell.h"

void	add_token(t_data *dt, t_type type)
{
	t_tokennode	*token;

	while (dt->line[dt->token.start] && ft_isspace(dt->line[dt->token.start]))
		(dt->token.start)++;
	if (dt->token.start == dt->token.end)
		return ;
	token = create_tokennode(type);
	if (type == COMMAND || type == RE_IN || type == RE_OUT || \
		type == RE_APPEND || type == RE_HERE)
	{
		dt->token.command_flag = ON;
		token->parsed_data = ft_substr(dt->line, dt->token.start, \
										dt->token.end - dt->token.start);
	}
	else if (type == PIPE || type == D_VERTICAL || type == D_AMPERSAND || \
		type == PRIORITY_START)
		dt->token.command_flag = OFF;
	if (!dt->token.head)
		dt->token.head = token;
	else
		dt->token.temp->next = token;
	dt->token.temp = token;
	dt->token.start = dt->token.end;
}
// Start index : first character of the token
// End Index: position after the last character of the token.

t_tokennode	*create_tokennode(t_type type)
{
	t_tokennode	*new_node;

	new_node = (t_tokennode *)malloc_s(sizeof(t_tokennode));
	new_node->type = type;
	new_node->parsed_data = NULLPOINTER;
	new_node->next = NULLPOINTER;
	return (new_node);
}
