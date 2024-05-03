/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 15:54:01 by flfische          #+#    #+#             */
/*   Updated: 2024/04/29 16:29:28 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// TODO: use ast input
int	ft_unset(char ***env, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_valid_env_key(argv[i]))
		{
			ft_print_error_env("not a valid identifier", "unset", argv[i]);
			return (1);
		}
		else
			ft_env_remove(env, argv[i]);
		i++;
	}
	return (0);
}
