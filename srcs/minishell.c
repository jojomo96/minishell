/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/04/26 18:35:31 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	**env;

	(void)argc;
	(void)argv;
	env = ft_strarr_cpy(envp);
	if (!env)
		return (1);
	ft_env(&env);
	ft_env_add(&env, "TEST", "42");
	ft_putendl_fd("--------------------------------", 1);
	ft_env(&env);
	ft_putendl_fd("--------------------------------", 1);
	ft_env_change(&env, "TEST", "21");
	ft_env(&env);
	ft_putendl_fd("--------------------------------", 1);
	ft_env_remove(&env, "TEST");
	ft_env_remove(&env, "TEST2");
	ft_env(&env);
	ft_strarr_free(env);
	return (0);
}
