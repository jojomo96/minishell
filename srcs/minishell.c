/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/21 18:33:21 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_handle_input(char *input)
{
	t_ast_node	**nodes;
	t_ast_node	*ast;

	nodes = ft_tokenize_input(input);
	if (!nodes)
		return (1);
	ast = NULL;
	build_ast(&ast, nodes);
	// ft_expand_arguments(ast);
	fr_traverse_and_process(ast, AST_TYPE_NODE, &ft_ast_move_arguments);
	ft_get_shell()->ast = ast;
	ft_execute(ft_get_shell(), ast);
	fr_traverse_and_process(ast, AST_TYPE_LEAF, &ft_wait_node);
	// write_ast_to_dot_file(ast);
	return (0);
}

void	ft_handle_input_loop(t_shell *ms)
{
	char	*input;
	bool	is_first;

	is_first = true;
	while (1)
	{
		if (is_first)
		{
			is_first = false;
			input = readline(PROMPT_DEFAULT);
		}
		else if (ms->exit_code)
			input = readline(PROMPT_ERROR);
		else
			input = readline(PROMPT_SUCCESS);
		if (!input)
		{
			write(STDOUT_FILENO, PROMPT_EXIT, sizeof(PROMPT_EXIT) - 1);
			ft_destroy_shell(ms, 1);
		}
		ft_history_add(input);
		ft_handle_input(input);
		free(input);
	}
}

void	ft_handle_input_pipe(void)
{
	char	*input;
	char	*line;

	line = get_next_line(STDIN_FILENO);
	input = ft_strtrim(line, "\n");
	free(line);
	ft_handle_input(input);
	free(input);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell				*ms;
	(void)argv;

	ft_signals_init();
	ft_history_init();
	ms = ft_get_shell();
	if (argc != 1 || ft_shell_init(ms, envp))
		return (1);
	if (isatty(STDIN_FILENO))
		ft_handle_input_loop(ms);
	else
		ft_handle_input_pipe();
	return (ft_destroy_shell(ms, 0));
}
