/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:28:56 by flfische          #+#    #+#             */
/*   Updated: 2024/05/25 15:05:18 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_right_fd(t_ast_node *node, int fd)
{
	t_ast_node	*right;

	right = node->u_data.s_node.right;
	while (right->type != AST_TYPE_LEAF)
		right = right->u_data.s_node.left;
	if (right->u_data.leaf.fd_in == STDIN_FILENO
		&& !right->u_data.leaf.heredoc_filename)
		right->u_data.leaf.fd_in = fd;
	return (0);
}

static int	set_left_fd(t_ast_node *node, int fd)
{
	t_ast_node	*left;

	left = node->u_data.s_node.left;
	while (left->type != AST_TYPE_LEAF)
	{
		if (left->u_data.s_node.op_type == OP_HEREDOC)
			left = left->u_data.s_node.left;
		else
			left = left->u_data.s_node.right;
	}
	left->u_data.leaf.fd_out = fd;
	return (0);
}

int	ft_exec_pipe(t_shell *ms, t_ast_node *node)
{
	int			status;
	int			pipe_fd[2];
	t_ast_node	*left;
	t_ast_node	*right;

	left = node->u_data.s_node.left;
	right = node->u_data.s_node.right;
	if (pipe(pipe_fd) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	set_left_fd(node, pipe_fd[1]);
	set_right_fd(node, pipe_fd[0]);
	fr_traverse_and_process(ms->ast, AST_TYPE_LEAF, &debug_print_node);
	if (left->type == AST_TYPE_LEAF)
		status = ft_exec_pipe_leaf(ms, left);
	else
		status = ft_execute(ms, left);
	if (right->type == AST_TYPE_LEAF)
		status = ft_exec_pipe_leaf(ms, right);
	else
		status = ft_execute(ms, right);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	return (status);
}
