/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:29:43 by flfische          #+#    #+#             */
/*   Updated: 2024/05/10 11:46:34 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO : add cmd execution of non - builtin commands
int	ft_execute(t_shell *ms, t_ast_node *node, int fd_out)
{
	t_builtin	builtin;

	builtin = ft_is_builtin(node->u_data.leaf.argv[0]);
	if (builtin != NONE)
		return (ft_exec_builtin(ms, builtin, node->u_data.leaf.argv, fd_out));
	return (0);
}
