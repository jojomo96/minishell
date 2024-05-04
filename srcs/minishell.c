/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz <jmoritz@studen.42heilbronn.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:00:05 by flfische          #+#    #+#             */
/*   Updated: 2024/05/04 09:24:18 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char* getTokenName(e_token_type token) {
    switch (token) {
        case NODE_ARGUMENT:
            return "NODE_ARGUMENT";
        case NODE_PIPE:
            return "NODE_PIPE";
        case NODE_REDIRECT_IN:
            return "NODE_REDIRECT_IN";
        case NODE_REDIRECT_OUT:
            return "NODE_REDIRECT_OUT";
        case NODE_APPEND_OUT:
            return "NODE_APPEND_OUT";
        case NODE_HEREDOC:
            return "NODE_HEREDOC";
        case NODE_SUBSHELL:
            return "NODE_SUBSHELL";
        case NODE_AND:
            return "NODE_AND";
        case NODE_OR:
            return "NODE_OR";
        default:
            return "Unknown token";
    }
}

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
	for (int i = 0; tokens[i]; i++)
	{
		printf("Token %d: %s		with type: %s\n", i, tokens[i]->content, getTokenName(tokens[i]->type));

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
	ft_tokens_free(tokens);
	// ft_gc_freeall();
	return (0);
}
