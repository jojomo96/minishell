/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:32:59 by flfische          #+#    #+#             */
/*   Updated: 2024/05/25 10:23:23 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_destroy_shell(t_shell *ms, int should_exit)
{
	debug_message("Destroying minishell");
	ft_strarr_free(ms->env);
	ft_strarr_free(ms->exp);
	free(ms->history_file);
	free(ms->heredoc_file);
	ft_gc_freeall();
	if (should_exit)
		exit(ms->exit_code);
	return (ms->exit_code);
}
