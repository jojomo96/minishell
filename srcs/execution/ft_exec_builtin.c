/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:22:13 by flfische          #+#    #+#             */
/*   Updated: 2024/05/10 14:56:50 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_builtin(t_shell *ms, t_builtin builtin, char **argv, int fd_out)
{
	if (builtin == BUILTIN_ECHO)
		ms->exit_code = ft_echo(argv, fd_out);
	else if (builtin == BUILTIN_CD)
		ms->exit_code = ft_cd(ms, argv[1], fd_out);
	else if (builtin == BUILTIN_PWD)
		ms->exit_code = ft_pwd(fd_out);
	else if (builtin == BUILTIN_EXPORT)
		ms->exit_code = ft_export(ms, argv, fd_out);
	else if (builtin == BUILTIN_UNSET)
		ms->exit_code = ft_unset(ms, argv);
	else if (builtin == BUILTIN_ENV)
		ms->exit_code = ft_env(ms, fd_out);
	else if (builtin == BUILTIN_EXIT)
		ft_exit(ms, argv, fd_out);
	return (ms->exit_code);
}
