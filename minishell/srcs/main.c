/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:18:14 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/28 02:58:14 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_data	*initialize(int argc, const char **argv, const char **envp);
static void		free_parse_data(t_data *data);

int	main(int argc, const char **argv, const char **envp)
{
	t_data	*data;

	data = initialize(argc, argv, envp);
	while (1)
	{
		rl_catch_signals = 0;
		signal_default();
		data->line = readline("minishell$ ");
		if (!data->line)
			eof_exit("exit\n");
		detect_and_handle_eof(data->line);
		if (data->line[0] != '\0')
			add_history(data->line);
		parse_commands(data);
		if (data->parse_tree)
			execute_commands(data);
		free_data(data);
	}
}

static t_data	*initialize(int argc, const char **argv, const char **envp)
{
	t_data	*data;

	if (argc != 1)
		exit(1);
	if (!ft_strcmp(argv[0], "minishell"))
		exit(1);
	data = (t_data *)malloc_s(sizeof(t_data));
	data->line = NULL;
	data->line_length = 0;
	data->token.head = NULL;
	data->token.temp = NULL;
	data->token.start = 0;
	data->token.end = 0;
	data->token.bracket_count = 0;
	data->token.command_flag = OFF;
	data->token.syntax_flag = OFF;
	data->env_list = init_envlist(envp);
	data->heredoc_list = NULL;
	data->parse_tree = NULL;
	return (data);
}

static void	free_parse_data(t_data *data)
{
	free(data->line);
	data->line = NULL;
	data->line_length = 0;
	free_tokens(data);
	free_parse_tree(data->parse_tree);
	data->parse_tree = NULL;
	free_env_list(data);
	free_heredoc_list_close_fd(data);
}
