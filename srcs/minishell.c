/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/14 13:15:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_ast_node	**nodes;
	t_ast_node	*ast;
	t_shell		*ms;

	(void)argv;
	ms = ft_get_shell();
	if (argc != 1 || ft_shell_init(ms, envp))
		return (1);

	nodes = ft_tokenize_input("echo test\"$USER\"");
	if (!nodes)
		return (1);
	ast = NULL;
	build_ast(&ast, nodes);
	ft_expand_arguments(ast);
	fr_traverse_and_process(ast, AST_TYPE_NODE, &ft_ast_move_arguments);

	ft_env(ms, 0);
	write_ast_to_dot_file(ast);
	return (ft_destroy_shell(ms, 0));
}
