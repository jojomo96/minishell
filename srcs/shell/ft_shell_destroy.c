/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:32:59 by flfische          #+#    #+#             */
/*   Updated: 2024/05/26 17:31:53 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_destroy_shell(t_shell *ms, int should_exit)
{
	debug_message("Destroying minishell");
	if (ms->env)
		ft_strarr_free(ms->env);
	if (ms->exp)
		ft_strarr_free(ms->exp);
	if (ms->history_file)
		free(ms->history_file);
	if (ms->heredoc_file)
		free(ms->heredoc_file);
	if (ms->ms_dir)
		free(ms->ms_dir);
	ft_gc_freeall();
	if (should_exit)
		exit(ms->exit_code);
	return (ms->exit_code);
}
