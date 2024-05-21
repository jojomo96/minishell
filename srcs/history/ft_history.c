/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:08:14 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/21 18:15:07 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_history_add(char *input)
{
	int			fd;

	if (input == NULL || strlen(input) == 0)
		return ;
	add_history(input);
	fd = open(HISTORY_FILE, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Error: could not open history file\n", STDERR_FILENO);
		return ;
	}
	if (write(fd, input, strlen(input)) < 0)
	{
		perror("Error writing to history file");
		close(fd);
		return ;
	}
	if (write(fd, "\n", 1) < 0)
	{
		perror("Error writing to history file");
		close(fd);
		return ;
	}
	close(fd);
}

static void	ft_remove_newline(char *line)
{
	size_t	len;

	len = strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	ft_history_init(void)
{
	int			fd;
	char		*line;

	fd = open(HISTORY_FILE, O_RDONLY | O_CREAT, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Error: could not open history file\n", STDERR_FILENO);
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_remove_newline(line);
		add_history(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
