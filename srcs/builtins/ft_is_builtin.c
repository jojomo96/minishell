/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:28:04 by flfische          #+#    #+#             */
/*   Updated: 2024/05/22 12:54:45 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static char	make_lower(unsigned int i, char c)
// {
// 	(void)i;
// 	return (ft_tolower(c));
// }

t_builtin	ft_is_builtin(char *cmd)
{
	char	*lower;

	lower = ft_strdup(cmd);
	if (!ft_strcmp(lower, "echo"))
		return (BUILTIN_ECHO);
	if (!ft_strcmp(lower, "cd"))
		return (BUILTIN_CD);
	if (!ft_strcmp(lower, "pwd"))
		return (BUILTIN_PWD);
	if (!ft_strcmp(lower, "export"))
		return (BUILTIN_EXPORT);
	if (!ft_strcmp(lower, "unset"))
		return (BUILTIN_UNSET);
	if (!ft_strcmp(lower, "env"))
		return (BUILTIN_ENV);
	if (!ft_strcmp(lower, "exit"))
		return (BUILTIN_EXIT);
	free(lower);
	return (NONE);
}
