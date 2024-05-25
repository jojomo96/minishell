/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:08:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/25 14:51:17 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void static	ft_handle_heredoc(char *delim, char *file_name)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_print_error(strerror(errno), 0, 0);
		return ;
	}
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			line = readline("> ");
			if (!line || !ft_strcmp(line, delim))
			{
				free(line);
				break ;
			}
			ft_remove_newline(line);
			write(fd, line, strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
	}
	else
	{
		line = get_next_line(STDIN_FILENO);
		while (line)
		{
			ft_remove_newline(line);
			if (!ft_strcmp(line, delim))
			{
				free(line);
				break ;
			}
			write(fd, line, strlen(line));
			write(fd, "\n", 1);
			free(line);
			line = get_next_line(STDIN_FILENO);
		}
	}
	close(fd);
}

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
	// expand file content
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
	// unlink
	dup2(standard_input, STDIN_FILENO);
	close(standard_input);
	return (ret);
}

void	ft_preprocess_heredoc(t_ast_node *node)
{
	char	*file_name;
	t_shell	*ms;

	ms = ft_get_shell();
	if (node->u_data.s_node.op_type != OP_HEREDOC)
		return ;
	debug_message("Preprocessing heredoc");
	debug_message_1("	with right node:",
			node->u_data.s_node.right->u_data.leaf.argv[0]);
	ft_switch_to_heredoc_mode();
	ms->heredoc_index += 1;
	file_name = ft_strjoin(ms->heredoc_file, ft_itoa(ms->heredoc_index));
	ft_handle_heredoc(node->u_data.s_node.right->u_data.leaf.argv[0],
		file_name);
	node->u_data.s_node.right->u_data.leaf.heredoc_filename = file_name;
	//TODO faile name to left child maybe
	ft_switch_to_normal_mode();
}
