/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:30:55 by flfische          #+#    #+#             */
/*   Updated: 2024/05/07 15:40:11 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_shell_init(t_shell *ms, char **envp)
{
	ms->env = ft_strarr_cpy(envp);
	if (!ms->env)
		return (1);
	ms->exp = ft_strarr_cpy(envp);
	if (!ms->exp)
		return (ft_strarr_free(ms->env), 1);
	if (ft_env_init(&ms->env) || ft_env_init(&ms->exp))
		return (ft_strarr_free(ms->env), ft_strarr_free(ms->exp), 1);
	ms->exit_code = 0;
	return (0);
}
