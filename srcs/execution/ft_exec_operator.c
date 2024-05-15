/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:19:29 by flfische          #+#    #+#             */
/*   Updated: 2024/05/15 11:52:59 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_and(t_shell *ms, t_ast_node *node)
{
	int			status;
	t_ast_node	*left;
	t_ast_node	*right;

	left = node->u_data.s_node.left;
	right = node->u_data.s_node.right;
	status = ft_execute(ms, left);
	if (left->type == AST_TYPE_LEAF && left->u_data.leaf.pid != -1)
		waitpid(left->u_data.leaf.pid, &status, 0);
	left->exit_status = WEXITSTATUS(status);
	ms->exit_code = left->exit_status;
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (1);
	status = ft_execute(ms, right);
	if (right->type == AST_TYPE_LEAF && right->u_data.leaf.pid != -1)
		waitpid(right->u_data.leaf.pid, &status, 0);
	right->exit_status = WEXITSTATUS(status);
	node->exit_status = right->exit_status;
	ms->exit_code = right->exit_status;
	return (status);
}

int	ft_exec_or(t_shell *ms, t_ast_node *node)
{
	int			status;
	t_ast_node	*left;
	t_ast_node	*right;

	left = node->u_data.s_node.left;
	right = node->u_data.s_node.right;
	status = ft_execute(ms, left);
	if (left->type == AST_TYPE_LEAF && left->u_data.leaf.pid != -1)
		waitpid(left->u_data.leaf.pid, &status, 0);
	left->exit_status = WEXITSTATUS(status);
	ms->exit_code = left->exit_status;
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		return (0);
	status = ft_execute(ms, right);
	if (right->type == AST_TYPE_LEAF && right->u_data.leaf.pid != -1)
		waitpid(right->u_data.leaf.pid, &status, 0);
	right->exit_status = WEXITSTATUS(status);
	node->exit_status = right->exit_status;
	ms->exit_code = right->exit_status;
	return (status);
}
