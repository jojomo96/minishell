/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:40:09 by flfische          #+#    #+#             */
/*   Updated: 2024/05/22 16:29:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_exit_status_err(t_ast_node *node)
{
	node->exit_status = 1;
	node->u_data.s_node.right->exit_status = 1;
	node->u_data.s_node.left->exit_status = 1;
	ft_get_shell()->exit_code = 1;
}

int	ft_exec_redirect_out(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	std_out;
	int	ret;

	ft_expand_arguments(node->u_data.s_node.right);
	std_out = dup(STDOUT_FILENO);
	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (set_exit_status_err(node), ft_print_error(strerror(errno), NULL,
				NULL), 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (close(fd), set_exit_status_err(node),
			ft_print_error(strerror(errno), NULL, NULL), 1);
	close(fd);
	ret = ft_execute(ms, node->u_data.s_node.left);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(std_out);
	if (node->u_data.s_node.left->exit_status == 1)
		set_exit_status_err(node);
	return (ret);
}

int	ft_exec_append_out(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	std_out;
	int	ret;

	ft_expand_arguments(node->u_data.s_node.right);
	std_out = dup(STDOUT_FILENO);
	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0],
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		return (set_exit_status_err(node), ft_print_error(strerror(errno),
				node->u_data.s_node.right->u_data.leaf.argv[0], NULL), 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (close(fd), set_exit_status_err(node),
			ft_print_error(strerror(errno), NULL, NULL), 1);
	close(fd);
	ret = ft_execute(ms, node->u_data.s_node.left);
	if (dup2(std_out, STDOUT_FILENO) == -1)
		return (ft_print_error(strerror(errno), NULL, NULL), 1);
	close(std_out);
	if (node->u_data.s_node.left->exit_status == 1)
		set_exit_status_err(node);
	return (ret);
}

int	ft_exec_redirect_in(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	std_in;
	int	ret;

	ft_expand_arguments(node->u_data.s_node.right);
	std_in = dup(STDIN_FILENO);
	fd = open(node->u_data.s_node.right->u_data.leaf.argv[0], O_RDONLY);
	if (fd == -1)
		return (set_exit_status_err(node), ft_print_error(strerror(errno),
				node->u_data.s_node.right->u_data.leaf.argv[0], NULL), 1);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (close(fd), set_exit_status_err(node),
			ft_print_error(strerror(errno), NULL, NULL), 1);
	close(fd);
	ret = ft_execute(ms, node->u_data.s_node.left);
	if (dup2(std_in, STDIN_FILENO) == -1)
		return (set_exit_status_err(node), ft_print_error(strerror(errno), NULL,
				NULL), 1);
	close(std_in);
	if (node->u_data.s_node.left->exit_status == 1)
		set_exit_status_err(node);
	return (ret);
}
