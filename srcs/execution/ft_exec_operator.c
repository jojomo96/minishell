/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_operator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:19:29 by flfische          #+#    #+#             */
/*   Updated: 2024/05/14 11:45:12 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_and(t_shell *ms, t_ast_node *node)
{
	int	ret;

	ret = ft_execute(ms, node->u_data.s_node.left, 1);
	if (ret == 0)
		ret = ft_execute(ms, node->u_data.s_node.right, 1);
	return (ret);
}

int	ft_exec_or(t_shell *ms, t_ast_node *node)
{
	int	ret;

	ret = ft_execute(ms, node->u_data.s_node.left, 1);
	if (ret != 0)
		ret = ft_execute(ms, node->u_data.s_node.right, 1);
	return (ret);
}
