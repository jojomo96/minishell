/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 11:56:46 by flfische          #+#    #+#             */
/*   Updated: 2024/05/25 20:25:31 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_set_left_fd_in(t_ast_node *node, int fd)
{
	t_ast_node	*left;

	left = node->u_data.s_node.left;
	while (left->type != AST_TYPE_LEAF)
	{
		if (left->type == AST_TYPE_NODE
			&& left->u_data.s_node.op_type == OP_AND)
			left = left->u_data.s_node.right;
		else
			left = left->u_data.s_node.left;
	}
	if (left->u_data.leaf.fd_in == STDIN_FILENO
		|| left->u_data.leaf.fd_from_pipe)
	{
		left->u_data.leaf.fd_in = fd;
		return (1);
	}
	return (0);
}

int	ft_exec_redirect_in(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	std_in;
	int	ret;

	if (handle_ambigous_redirect(node))
		return (1);
	std_in = dup(STDIN_FILENO);
	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0], O_RDONLY);
	if (fd == -1)
		return (red_set_exit_err(node, true, true), 1);
	ft_set_left_fd_in(node, fd);
	if (node->u_data.s_node.left->type == AST_TYPE_LEAF
		&& node->u_data.s_node.left->u_data.leaf.fd_in != fd && close(fd) != -1)
		fd = node->u_data.s_node.left->u_data.leaf.fd_in;
	if (dup2(fd, STDIN_FILENO) == -1)
		return (close(fd), red_set_exit_err(node, false, true), 1);
	ret = ft_execute(ms, node->u_data.s_node.left);
	if (dup2(std_in, STDIN_FILENO) == -1)
		return (red_set_exit_err(node, false, true), 1);
	close(std_in);
	if (node->u_data.s_node.left->exit_status == 1)
		red_set_exit_err(node, false, false);
	return (ret);
}
