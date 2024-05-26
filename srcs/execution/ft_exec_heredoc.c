/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:08:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 17:42:06 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_heredoc(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	ret;
	int	standard_input;

	debug_message("Executing heredoc");
	fd = open(node->u_data.s_node.right->u_data.leaf.heredoc_filename,
			O_RDONLY);
	if (fd < 0)
		return (ft_print_error(strerror(errno), 0, 0), 1);
	ft_set_left_fd_in(node, fd);
	if (node->u_data.s_node.left->type == AST_TYPE_LEAF
		&& node->u_data.s_node.left->u_data.leaf.fd_in != fd && close(fd) != -1)
		fd = node->u_data.s_node.left->u_data.leaf.fd_in;
	standard_input = dup(STDIN_FILENO);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		ft_print_error(strerror(errno), 0, 0);
		close(fd);
		return (0);
	}
	ret = ft_execute(ms, node->u_data.s_node.left);
	unlink(node->u_data.s_node.right->u_data.leaf.heredoc_filename);
	dup2(standard_input, STDIN_FILENO);
	close(standard_input);
	return (ret);
}

static void	set_left_filename(t_ast_node *node, char *file_name)
{
	t_ast_node	*left;

	left = node->u_data.s_node.left;
	while (left->type != AST_TYPE_LEAF)
	{
		left = left->u_data.s_node.right;
	}
	left->u_data.leaf.heredoc_filename = file_name;
}

void	ft_preprocess_heredoc(t_ast_node *node)
{
	char	*file_name;
	t_shell	*ms;

	ms = ft_get_shell();
	if (node->u_data.s_node.op_type != OP_HEREDOC || g_interrupted)
		return ;
	debug_message("Preprocessing heredoc");
	debug_message_1("	with right node:",
			node->u_data.s_node.right->u_data.leaf.argv[0]);
	ft_switch_to_heredoc_mode();
	ms->heredoc_index += 1;
	file_name = ft_gc_safe(ft_strjoin(ms->heredoc_file,
				ft_gc_safe(ft_itoa(ms->heredoc_index))));
	ft_heredoc_read_input(node->u_data.s_node.right->u_data.leaf.argv[0],
		file_name);
	node->u_data.s_node.right->u_data.leaf.heredoc_filename = file_name;
	set_left_filename(node, file_name);
	ft_switch_to_normal_mode();
}
