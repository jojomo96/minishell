/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:22:13 by flfische          #+#    #+#             */
/*   Updated: 2024/05/10 11:29:14 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_builtin(t_shell *ms, t_builtin builtin, char **argv, int fd_out)
{
	if (builtin == BUILTIN_ECHO)
		return (ft_echo(argv, fd_out));
	if (builtin == BUILTIN_CD)
		return (ft_cd(ms, argv[1], fd_out));
	if (builtin == BUILTIN_PWD)
		return (ft_pwd(fd_out));
	if (builtin == BUILTIN_EXPORT)
		return (ft_export(ms, argv, fd_out));
	if (builtin == BUILTIN_UNSET)
		return (ft_unset(ms, argv));
	if (builtin == BUILTIN_ENV)
		return (ft_env(ms, fd_out));
	if (builtin == BUILTIN_EXIT)
		ft_exit(ms, argv, fd_out);
	return (0);
}
