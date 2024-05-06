/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/06 18:00:13 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	**env;
	char	**exp;

	(void)argc;
	(void)argv;
	env = ft_strarr_cpy(envp);
	exp = ft_strarr_cpy(envp);
	if (!env || !exp || ft_env_init(&env) != 0)
		return (1);
	ft_export(&env, &exp, NULL);
	ft_export(&env, &exp, (char *[]){"b=/home", "A", "a=flfische", "c", NULL});
	printf("env:\n");
	ft_env(&env);
	printf("exp:\n");
	ft_export(&env, &exp, NULL);
	ft_strarr_free(env);
	return (0);
}
