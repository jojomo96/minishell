/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:28:04 by flfische          #+#    #+#             */
/*   Updated: 2024/05/10 11:28:44 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	ft_is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (BUILTIN_ECHO);
	if (!ft_strcmp(cmd, "cd"))
		return (BUILTIN_CD);
	if (!ft_strcmp(cmd, "pwd"))
		return (BUILTIN_PWD);
	if (!ft_strcmp(cmd, "export"))
		return (BUILTIN_EXPORT);
	if (!ft_strcmp(cmd, "unset"))
		return (BUILTIN_UNSET);
	if (!ft_strcmp(cmd, "env"))
		return (BUILTIN_ENV);
	if (!ft_strcmp(cmd, "exit"))
		return (BUILTIN_EXIT);
	return (NONE);
}
