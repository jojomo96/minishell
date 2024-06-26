/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:09 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 18:14:24 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	red_set_exit_err(t_ast_node *node, bool print_content, bool print)
{
	node->exit_status = 1;
	node->u_data.s_node.right->exit_status = 1;
	node->u_data.s_node.left->exit_status = 1;
	ft_get_shell()->exit_code = 1;
	if (print_content && print)
		ft_print_error(strerror(errno),
			node->u_data.s_node.right->u_data.leaf.argv[0], NULL);
	else if (print)
		ft_print_error(strerror(errno), NULL, NULL);
}

static int	set_left_fd(t_ast_node *node, int fd)
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
	if (left->u_data.leaf.fd_out == STDOUT_FILENO)
	{
		left->u_data.leaf.fd_out = fd;
		return (1);
	}
	return (0);
}

int	handle_ambigous_redirect(t_ast_node *node)
{
	char	*initial_val;

	initial_val = ft_gc_safe(ft_strdup(\
		node->u_data.s_node.right->u_data.leaf.argv[0]));
	ft_expand_arguments(node->u_data.s_node.right);
	if (node->u_data.s_node.right->u_data.leaf.argv[1] != NULL)
	{
		ft_putstr_fd("minishell: ", STDERR_FILENO);
		ft_putstr_fd(initial_val, STDERR_FILENO);
		ft_putstr_fd(": ambiguous redirect\n", STDERR_FILENO);
		node->exit_status = 1;
		node->u_data.s_node.right->exit_status = 1;
		node->u_data.s_node.left->exit_status = 1;
		ft_get_shell()->exit_code = 1;
		ft_free(initial_val);
		return (1);
	}
	ft_free(initial_val);
	return (0);
}

int	ft_exec_redirect_out(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	std_out;
	int	ret;

	if (handle_ambigous_redirect(node))
		return (1);
	std_out = dup(STDOUT_FILENO);
	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	set_left_fd(node, fd);
	if (fd == -1)
		return (red_set_exit_err(node, true, true), 1);
	if (node->u_data.s_node.left->type == AST_TYPE_LEAF
		&& node->u_data.s_node.left->u_data.leaf.fd_out != fd
		&& close(fd) != -1)
		fd = node->u_data.s_node.left->u_data.leaf.fd_out;
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (close(fd), red_set_exit_err(node, false, true), 1);
	ret = ft_execute(ms, node->u_data.s_node.left);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(std_out);
	if (node->u_data.s_node.left->exit_status == 1)
		red_set_exit_err(node, false, false);
	return (ret);
}

int	ft_exec_append_out(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	std_out;
	int	ret;

	if (handle_ambigous_redirect(node))
		return (1);
	std_out = dup(STDOUT_FILENO);
	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0],
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	set_left_fd(node, fd);
	if (fd == -1)
		return (red_set_exit_err(node, true, true), 1);
	if (node->u_data.s_node.left->type == AST_TYPE_LEAF
		&& node->u_data.s_node.left->u_data.leaf.fd_out != fd
		&& close(fd) != -1)
		fd = node->u_data.s_node.left->u_data.leaf.fd_out;
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (close(fd), red_set_exit_err(node, false, true), 1);
	ret = ft_execute(ms, node->u_data.s_node.left);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(std_out);
	if (node->u_data.s_node.left->exit_status == 1)
		red_set_exit_err(node, false, false);
	return (ret);
}
