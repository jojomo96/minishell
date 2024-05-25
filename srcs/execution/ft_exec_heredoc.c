/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:08:49 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/25 11:06:39 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void static	ft_handle_heredoc(char *delim)
{
	char	*line;
	int		fd;

	fd = open(ft_get_shell()->heredoc_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

static int	ft_execute_command(t_shell *ms, t_ast_node *node)
{
	int	fd;
	int	standard_input;

	fd = open(ft_get_shell()->heredoc_file, O_RDONLY);
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
	debug_message("Executing heredoc");
	ft_switch_to_heredoc_mode();
	ft_handle_heredoc(node->u_data.s_node.right->u_data.leaf.argv[0]);
	ft_execute_command(ms, node->u_data.s_node.left);
	ft_switch_to_normal_mode();
	return (0);
}
