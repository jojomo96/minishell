/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz <jmoritz@studen.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/04 09:43:04 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(int argc, char **argv, char **envp)
{
	// char	**env;

	(void)argc;
	(void)argv;
	(void)envp;

	char *input = "&& || | cat -l     \" test \"test asd \'test\"test\" test\'";
	t_token **tokens = ft_tokenize_input(input);
	if (!tokens)
		return (1);
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
	ft_tokens_free(tokens);
	// ft_gc_freeall();
	return (0);
}
