/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_out.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:09 by flfische          #+#    #+#             */
/*   Updated: 2024/05/14 16:29:38 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_redirect_out(t_shell *ms, t_ast_node *node)
{
	int	fd;

	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(fd);
	return (ft_execute(ms, node->u_data.s_node.left));
}

int	ft_exec_append_out(t_shell *ms, t_ast_node *node)
{
	int	fd;

	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0],
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(fd);
	return (ft_execute(ms, node->u_data.s_node.left));
}

int	ft_exec_redirect_in(t_shell *ms, t_ast_node *node)
{
	int	fd;

	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0], O_RDONLY);
	if (fd == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(fd);
	return (ft_execute(ms, node->u_data.s_node.left));
}
