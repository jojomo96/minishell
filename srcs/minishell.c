/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/13 12:52:13 by flfische         ###   ########.fr       */
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
	nodes = ft_tokenize_input("export A=TEST && env");
	if (!nodes)
		return (1);
	ast = NULL;
	build_ast(&ast, nodes);
	ft_env(ms, 0);
	write_ast_to_dot_file(ast);
	return (ft_destroy_shell(ms, 0));
}
