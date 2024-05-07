/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/07 14:56:33 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_shell(t_shell *ms, char **envp)
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

int	ft_destroy_shell(t_shell *ms)
{
	ft_strarr_free(ms->env);
	ft_strarr_free(ms->exp);
	return (ms->exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	ms;

	(void)argv;
	if (argc != 1 || ft_init_shell(&ms, envp))
		return (1);
	ft_export(&ms.env, &ms.exp, NULL);
	ft_export(&ms.env, &ms.exp, (char *[]){"b=/home", "A", "a=flfische", "c",
		NULL});
	printf("env:\n");
	ft_env(&ms.env);
	printf("exp:\n");
	ft_export(&ms.env, &ms.exp, NULL);
	ft_unset(&ms, (char *[]){"unset", "a", "b", "c", "d", NULL});
	printf("env:\n");
	ft_env(&ms.env);
	printf("exp:\n");
	ft_export(&ms.env, &ms.exp, NULL);
	return (ft_destroy_shell(&ms));
}
