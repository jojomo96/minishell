/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/25 13:06:57 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_quotes(char *input)
{
	bool	in_single_quote;
	bool	in_double_quote;
	int		i;

	in_single_quote = false;
	in_double_quote = false;
	i = 0;
	while (input[i])
		ft_toggle_quotes(&input[i++], &in_single_quote, &in_double_quote);
	if (in_single_quote)
	{
		ft_print_error("unexpected EOF while looking for matching `''", NULL,
			NULL);
	}
	if (in_double_quote)
	{
		ft_print_error("unexpected EOF while looking for matching `\"'", NULL,
			NULL);
	}
	return (in_single_quote || in_double_quote);
}

int	ft_handle_input(char *input)
{
	t_ast_node	**nodes;
	t_ast_node	*ast;

	ft_get_shell()->has_error = false;
	if (check_quotes(input))
		return (1);
	nodes = ft_tokenize_input(input);
	if (!nodes)
		return (1);
	if (nodes[0] == NULL)
		return (ft_free(nodes), 0);
	ast = NULL;
	build_ast(&ast, nodes);
	if (!ast)
		return (ft_free(nodes), 0);
	if (ft_traverse_process_return(ast, AST_TYPE_NODE, &ft_ast_validate))
		return (ft_free(nodes), ft_get_shell()->exit_code = 2, 1);
	if (ft_get_shell()->has_error)
		return (ft_free(nodes), 1);
	fr_traverse_and_process(ast, AST_TYPE_NODE, &ft_ast_move_arguments);
	fr_traverse_and_process(ast, AST_TYPE_NODE, &ft_preprocess_heredoc);
	ft_get_shell()->ast = ast;
	ft_execute(ft_get_shell(), ast);
	fr_traverse_and_process(ast, AST_TYPE_LEAF, &ft_wait_node);
	write_ast_to_dot_file(ast);
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
	while (line)
	{
		input = ft_strtrim(line, "\n");
		free(line);
		ft_handle_input(input);
		free(input);
		line = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*ms;

	(void)argv;
	ft_signals_init();
	ms = ft_get_shell();
	ms->history_file = ft_strjoin(getcwd(NULL, 0), HISTORY_FILE);
	ms->heredoc_file = ft_strjoin(getcwd(NULL, 0), HEREDOC_FILE);
	ms->heredoc_index = -1;
	ft_history_init();
	if (argc != 1 || ft_shell_init(ms, envp))
		return (1);
	if (isatty(STDIN_FILENO))
		ft_handle_input_loop(ms);
	else
		ft_handle_input_pipe();
	return (ft_destroy_shell(ms, 0));
}
