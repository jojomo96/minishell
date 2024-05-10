/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:32:59 by flfische          #+#    #+#             */
/*   Updated: 2024/05/10 10:12:54 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_destroy_shell(t_shell *ms, int should_exit)
{
	ft_strarr_free(ms->env);
	ft_strarr_free(ms->exp);
	ft_gc_freeall();
	if (should_exit)
		exit(ms->exit_code);
	return (ms->exit_code);
}
