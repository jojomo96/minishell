/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:09 by flfische          #+#    #+#             */
/*   Updated: 2024/05/15 10:45:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_redirect_out(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	std_out;
	int	ret;

	std_out = dup(STDOUT_FILENO);
	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (close(fd), ft_print_error(strerror(errno), NULL, NULL), 1);
	close(fd);
	ret = ft_execute(ms, node->u_data.s_node.left);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(std_out);
	return (ret);
}

int	ft_exec_append_out(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	std_out;
	int	ret;

	std_out = dup(STDOUT_FILENO);
	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0],
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (close(fd), ft_print_error(strerror(errno), NULL, NULL), 1);
	close(fd);
	ret = ft_execute(ms, node->u_data.s_node.left);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(std_out);
	return (ret);
}

int	ft_exec_redirect_in(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	std_in;
	int	ret;

	std_in = dup(STDIN_FILENO);
	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0], O_RDONLY);
	if (fd == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (close(fd), ft_print_error(strerror(errno), NULL, NULL), 1);
	close(fd);
	ret = ft_execute(ms, node->u_data.s_node.left);
	if (dup2(std_in, STDIN_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(std_in);
	return (ret);
}
