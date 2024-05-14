/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/14 17:31:01 by jmoritz          ###   ########.fr       */
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
	ft_expand_arguments(ast);
	fr_traverse_and_process(ast, AST_TYPE_NODE, &ft_ast_move_arguments);
	write_ast_to_dot_file(ast);
	return (0);
}

void	handle_input_loop(t_shell *ms)
{
	char	*input;
	char	*line;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			if (ms->exit_code)
				input = readline(PROMPT_ERROR);
			else
				input = readline(PROMPT_SUCCESS);
			if (input == ((void *)0))
				break ;
			add_history(input);
			ft_handle_input(input);
			free(input);
		}
	}
	else
	{
		line = get_next_line(fileno(stdin));
		input = ft_strtrim(line, "\n");
		ft_handle_input(input);
		return (free(line), free(input));
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	*ms;

	(void)argv;
	ms = ft_get_shell();
	if (argc != 1 || ft_shell_init(ms, envp))
		return (1);
	handle_input_loop(ms);
	ft_env(ms, 0);
	return (ft_destroy_shell(ms, 0));
}
