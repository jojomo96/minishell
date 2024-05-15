/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:18:51 by flfische          #+#    #+#             */
/*   Updated: 2024/05/15 11:49:29 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_wait_node(t_ast_node *node)
{
	int	status;

	if (node->type == AST_TYPE_LEAF)
	{
		if (node->u_data.leaf.pid == -1)
			return ;
		waitpid(node->u_data.leaf.pid, &status, 0);
		node->exit_status = WEXITSTATUS(status);
		ft_get_shell()->exit_code = node->exit_status;
	}
}
