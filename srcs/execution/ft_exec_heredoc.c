/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:08:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/25 12:52:56 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void static	ft_handle_heredoc(char *delim, char	*file_name)
{
	char	*line;
	int		fd;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_print_error(strerror(errno), 0, 0);
		return ;
	}
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
	close(fd);
}

static int	ft_execute_command(t_shell *ms, t_ast_node *node, char *file_name)
{
	int	fd;
	int	standard_input;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_print_error(strerror(errno), 0, 0);
		return (1);
	}
	standard_input = dup(STDIN_FILENO);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		ft_print_error(strerror(errno), 0, 0);
		close(fd);
		return (0);
	}
	close(fd);
	ft_execute(ms, node);
	dup2(standard_input, STDIN_FILENO);
	close(standard_input);
	return (0);
}

int	ft_exec_heredoc(t_shell *ms, t_ast_node *node)
{
	char *file_name;

	debug_message("Executing heredoc");


	ft_execute_command(ms, node->u_data.s_node.left, file_name);
	free(file_name);
	ft_switch_to_normal_mode();
	return (0);
}

int	ft_preprocess_heredoc(t_shell *ms, t_ast_node *node)
{
	char	*file_name;

	if (node->u_data.s_node.op_type != OP_HEREDOC)
		return (0);
	debug_message("Preprocessing heredoc");
	debug_message_1("	with right node:",
		node->u_data.s_node.right->u_data.leaf.argv[0]);

	ft_switch_to_heredoc_mode();
	ms->heredoc_index += 1;
	file_name = ft_strjoin(ms->heredoc_file, ft_itoa(ms->heredoc_index));
	ft_handle_heredoc(node->u_data.s_node.right->u_data.leaf.argv[0], file_name);
	node->u_data.s_node.right->u_data.leaf.heredoc_filename = file_name;
	ft_switch_to_normal_mode();
	return (1);
}
