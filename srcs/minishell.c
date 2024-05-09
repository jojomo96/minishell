/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/09 16:03:46 by jmoritz          ###   ########.fr       */
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
	nodes = ft_tokenize_input("(echo ok1 && echo ok2 || cd /fail3 && echo ok4 || echo ok5 || (echo ok6 && echo ok7))");
	if (!nodes)
		return (1);
	ast = NULL;
	build_ast(&ast, nodes);
    write_ast_to_dot_file(ast);
	return (ft_destroy_shell(&ms));
}
