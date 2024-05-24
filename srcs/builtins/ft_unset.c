/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:54:01 by flfische          #+#    #+#             */
/*   Updated: 2024/05/24 18:03:21 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_invalid_env_key(char *key)
{
	if (key[0] == '-')
	{
		ft_print_error_env("invalid option", "unset", key);
		return (2);
	}
	else
		ft_print_error_env("not a valid identifier", "unset", key);
	return (1);
}

int	ft_unset(t_shell *ms, char **argv)
{
	int	i;
	int	exit_code;

	debug_message("executing builtin: unset");
	i = 1;
	exit_code = 0;
	while (argv[i])
	{
		if (!ft_valid_env_key(argv[i]))
			exit_code = handle_invalid_env_key(argv[i]);
		else
		{
			ft_env_remove(&ms->env, argv[i]);
			ft_env_remove(&ms->exp, argv[i]);
		}
		i++;
	}
	return (exit_code);
}
