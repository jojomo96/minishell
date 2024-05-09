/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:32:59 by flfische          #+#    #+#             */
/*   Updated: 2024/05/07 15:33:17 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_destroy_shell(t_shell *ms)
{
	ft_strarr_free(ms->env);
	ft_strarr_free(ms->exp);
	ft_gc_freeall();
	return (ms->exit_code);
}
