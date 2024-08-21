/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:18:14 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/21 21:11:37 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_data	*initialize(int argc, char **argv, char **envp);
static void		detect_and_handle_eof(char *line);
static void		free_parse_data(t_data *data);

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = initialize(argc, argv, envp);
	while (1)
	{
		rl_catch_signals = 0;
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
		data->line = readline("minishell$ ");
		detect_and_handle_eof(data->line);
		if (data->line[0] != '\0')
			add_history(data->line);
		parse_commands(data);
		if (data->parse_tree)
			execute_commands(data);
		free_parse_data(data);
		free(data->line);
	}
}

static t_data	*initialize(int argc, char **argv, char **envp)
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
	data->token.tail = NULL;
	data->token.start = 0;
	data->token.end = 0;
	data->token.bracket_count = 0;
	data->token.command_flag = OFF;
	data->token.syntax_flag = OFF;
	data->env_list = init_envlist(envp);
	data->parse_tree = NULL;
}

static void	detect_and_handle_eof(char *line)
{
	if (!line)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		exit(g_exit_status);
	}
}

static void	free_parse_data(t_data *data)
{
	(void)data;
}
