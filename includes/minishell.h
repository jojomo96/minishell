/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:03:47 by flfische          #+#    #+#             */
/*   Updated: 2024/05/10 14:40:59 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* INCLUDES */
# include "../libft/libft.h"
# include "ast.h"
# include "builtins.h"
# include "debug.h"
# include "environment.h"
# include "errors.h"
# include "execution.h"
# include "gcollector.h"
# include "shellutils.h"
# include "utils.h"
/* EXTERNAL INCLUDES */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef DEBUG
#  define DEBUG 1
# endif

# define SHELL_NAME "minishell"

typedef struct s_shell
{
	int		exit_code;
	char	**env;
	char	**exp;
}			t_shell;

#endif
