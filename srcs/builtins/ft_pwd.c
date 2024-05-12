/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:21:57 by flfische          #+#    #+#             */
/*   Updated: 2024/05/12 10:38:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(int fd_out)
{
	char	*pwd;

	debug_message("executing builtin: pwd");
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		ft_print_error(strerror(errno), "pwd", NULL);
		return (1);
	}
	ft_putendl_fd(pwd, fd_out);
	free(pwd);
	return (0);
}
