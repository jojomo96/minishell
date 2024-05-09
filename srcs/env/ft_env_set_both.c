/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_set_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:59:17 by flfische          #+#    #+#             */
/*   Updated: 2024/05/09 14:04:49 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env_set_both(t_shell *ms, char *key, char *val)
{
	int	ret;

	if (!ft_valid_env_key(key))
	{
		ft_print_error_env("not a valid identifier", "export", key);
		return (-1);
	}
	ret = ft_env_set(&ms->env, key, val);
	if (ret == -1)
		return (-1);
	ret = ft_env_set(&ms->exp, key, val);
	if (ret == -1)
		return (-1);
	return (0);
}
