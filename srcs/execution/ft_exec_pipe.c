/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:28:56 by flfische          #+#    #+#             */
/*   Updated: 2024/05/15 14:18:32 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_right_fd(t_ast_node *node, int fd)
{
	t_ast_node	*right;

	right = node->u_data.s_node.right;
	while (right->type != AST_TYPE_LEAF)
		right = right->u_data.s_node.left;
	right->u_data.leaf.fd_in = fd;
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
	left->u_data.leaf.fd_out = pipe_fd[1];
	set_right_fd(node, pipe_fd[0]);
	if (left->type == AST_TYPE_LEAF)
		status = ft_exec_pipe_leaf(ms, left);
	else
		status = ft_execute(ms, left);
	if (left->type == AST_TYPE_LEAF && left->u_data.leaf.pid != -1)
		waitpid(left->u_data.leaf.pid, &status, 0);
	left->u_data.leaf.exit_status = WEXITSTATUS(status);
	close(pipe_fd[1]);
	if (right->type == AST_TYPE_LEAF)
		status = ft_exec_pipe_leaf(ms, right);
	else
		status = ft_execute(ms, right);
	return (status);
}
