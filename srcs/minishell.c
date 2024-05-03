/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/04/27 13:54:24 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	// char	**env;

	(void)argc;
	(void)argv;
	(void)envp;

	char *input = "&& || | cat -l";
	t_token **tokens = ft_tokenize_input(input);
	if (!tokens)
		return (1);
	for (int i = 0; tokens[i]; i++)
	{
		printf("Token %d: %s, whith type: %d\n", i, tokens[i]->content, tokens[i]->type);
	}
	// env = ft_strarr_cpy(envp);
	// if (!env)
	// 	return (1);
	// ft_env(&env);
	// ft_env_add(&env, "TEST", "42");
	// ft_putendl_fd("--------------------------------", 1);
	// ft_env(&env);
	// ft_putendl_fd("--------------------------------", 1);
	// ft_env_change(&env, "TEST", "21");
	// ft_env(&env);
	// ft_putendl_fd("--------------------------------", 1);
	// ft_env_remove(&env, "TEST");
	// ft_env_remove(&env, "TEST2");
	// ft_env(&env);
	// ft_strarr_free(env);
	return (0);
}
