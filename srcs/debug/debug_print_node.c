/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:14:10 by flfische          #+#    #+#             */
/*   Updated: 2024/05/21 20:22:41 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	debug_print_node(t_ast_node *node)
{
	if (DEBUG)
	{
		ft_putstr_fd(BOLD, STDERR_FILENO);
		ft_putstr_fd(UNDERLINE, STDERR_FILENO);
		ft_putstr_fd(BLUE, STDERR_FILENO);
		ft_putstr_fd("DEBUG:", STDERR_FILENO);
		ft_putstr_fd(RESET, STDERR_FILENO);
		ft_putstr_fd(" ", STDERR_FILENO);
		ft_putstr_fd(BLUE, STDERR_FILENO);
		if (node->type == AST_TYPE_LEAF)
		{
			ft_putstr_fd("LEAF: ", STDERR_FILENO);
			ft_putstr_fd(node->u_data.leaf.argv[0], STDERR_FILENO);
			ft_putstr_fd("	", STDERR_FILENO);
			ft_putnbr_fd(node->u_data.leaf.fd_in, STDERR_FILENO);
			ft_putstr_fd(" ", STDERR_FILENO);
			ft_putnbr_fd(node->u_data.leaf.fd_out, STDERR_FILENO);
			ft_putendl_fd("", STDERR_FILENO);
		}
		else
		{
			ft_putstr_fd("NODE: ", STDERR_FILENO);
			ft_putnbr_fd(node->type, STDERR_FILENO);
			ft_putstr_fd(" ", STDERR_FILENO);
			ft_putnbr_fd(node->u_data.s_node.op_type, STDERR_FILENO);
			ft_putendl_fd("", STDERR_FILENO);
		}
		ft_putstr_fd(RESET, STDERR_FILENO);
	}
}
