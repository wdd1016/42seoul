/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:18:14 by juyojeon          #+#    #+#             */
/*   Updated: 2024/08/18 04:13:48 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_data	*initialize(int argc, char **argv, char **envp);
static void		detect_and_handle_eof(char *line);
static void		free_parsed_data(t_data *data);

int main(int argc, char **argv, char **envp)
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
		if (data->pipe_list->next_pipeline)
			execute_commands(data);
		free_parsed_data(data);
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
	data = (t_data *)malloc(sizeof(t_data));
	data->line = NULL;
	data->env_list = init_envlist(envp);
	data->pipe_list = NULL;
	data->token_list = NULL;
}

static void	detect_and_handle_eof(char *line)
{
	if (!line)
	{
		write(STDOUT_FILENO, "exit\n", 5);
		exit(g_exit_status);
	}
}

static void	free_parsed_data(t_data *data)
{
	(void)data;
}
