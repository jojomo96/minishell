/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/09 13:20:03 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*create_complex_ast(void)
{
	t_ast_node	*root;
	t_ast_node	*and_right;
	t_ast_node	*echo_hello;
	t_ast_node	*grep_hello;
	t_ast_node	*echo_done;
	t_ast_node	*redirect_node;

	// Allocate nodes
	root = malloc(sizeof(t_ast_node));
	and_right = malloc(sizeof(t_ast_node));
	echo_hello = malloc(sizeof(t_ast_node));
	grep_hello = malloc(sizeof(t_ast_node));
	echo_done = malloc(sizeof(t_ast_node));
	redirect_node = malloc(sizeof(t_ast_node));
	// Setup leaf nodes
	echo_hello->type = AST_TYPE_LEAF;
	echo_hello->u_data.leaf.argv = malloc(sizeof(char *) * 2);
	echo_hello->u_data.leaf.argv[0] = "echo hello";
	grep_hello->type = AST_TYPE_LEAF;
	grep_hello->u_data.leaf.argv = malloc(sizeof(char *) * 2);
	grep_hello->u_data.leaf.argv[0] = "grep hello";
	echo_done->type = AST_TYPE_LEAF;
	echo_done->u_data.leaf.argv = malloc(sizeof(char *) * 3);
	echo_done->u_data.leaf.argv[0] = "echo";
	echo_done->u_data.leaf.argv[1] = "done";
	redirect_node->type = AST_TYPE_NODE;
	redirect_node->u_data.s_node.op_type = OP_REDIRECT_OUT;
	redirect_node->u_data.s_node.left = echo_hello;
	redirect_node->u_data.s_node.right = NULL;
	// Normally we would specify the file node
	// Setup pipe node
	root->type = AST_TYPE_NODE;
	root->u_data.s_node.op_type = OP_PIPE;
	root->u_data.s_node.left = redirect_node;
	root->u_data.s_node.right = grep_hello;
	// Setup AND node
	and_right->type = AST_TYPE_NODE;
	and_right->u_data.s_node.op_type = OP_AND;
	and_right->u_data.s_node.left = root;
	and_right->u_data.s_node.right = echo_done;
	// The root of this tree now becomes the AND operation
	return (and_right);
}

int	main(int argc, char **argv, char **envp)
{
	t_ast_node	**nodes;
	t_ast_node	*ast;

	// char	**env;
	(void)argc;
	(void)argv;
	(void)envp;
	// t_ast_node *root = create_complex_ast();
	// write_ast_to_dot_file(root);
	// ft_ast_free_node(root);
	nodes = ft_tokenize_input("echo test >> file.txt && echo done)");
	if (!nodes)
		return (1);
	ast = NULL;
	build_ast(&ast, nodes);
    // write_ast_to_dot_file(ast);
	ft_gc_freeall();
	return (0);
}
