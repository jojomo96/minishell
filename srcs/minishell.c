/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/13 09:45:28 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_ast_node	**nodes;
	t_ast_node	*ast;
	t_shell	ms;

	(void)argv;
	if (argc != 1 || ft_shell_init(&ms, envp))
		return (1);

	// char	**env;
	nodes = ft_tokenize_input("echo 1 2 3 >> a b c >> d e f");
	if (!nodes)
		return (1);
	ast = NULL;
	build_ast(&ast, nodes);
	fr_traverse_and_process(ast, AST_TYPE_NODE, &ft_ast_move_arguments);
	write_ast_to_dot_file(ast);
	return (ft_destroy_shell(&ms));
}
