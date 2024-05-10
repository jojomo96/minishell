/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:32:59 by flfische          #+#    #+#             */
/*   Updated: 2024/05/10 10:09:48 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_destroy_shell(t_shell *ms)
{
	if (DEBUG)
		printf("Destroying shell\n");
	ft_strarr_free(ms->env);
	ft_strarr_free(ms->exp);
	ft_gc_freeall();
	return (ms->exit_code);
}
