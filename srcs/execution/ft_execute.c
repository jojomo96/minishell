/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:29:43 by flfische          #+#    #+#             */
/*   Updated: 2024/05/14 11:25:30 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execute(t_shell *ms, t_ast_node *node)
{
	return (0);
}

int	ft_execute_leaf(t_shell *ms, t_ast_node *node)
{
	char	*builtin;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (pid == 0)
	{
		builtin = ft_is_builtin(node->u_data.leaf.argv[0]);
		if (builtin)
			ms->exit_code = ft_exec_builtin(ms, builtin, node->u_data.leaf.argv,
					node->u_data.leaf.fd_out);
		else
			ms->exit_code = ft_exec_command(ms, node);
		ft_destroy_shell(ms, 1);
	}
	return (0);
}

// add expander
int	ft_execute_node(t_shell *ms, t_ast_node *node)
{
}
