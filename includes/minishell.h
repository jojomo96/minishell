/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:03:47 by flfische          #+#    #+#             */
/*   Updated: 2024/05/25 11:58:43 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* EXTERNAL INCLUDES */
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
/* INCLUDES */
# include "../libft/libft.h"
# include "ast.h"
# include "builtins.h"
# include "colors.h"
# include "debug.h"
# include "environment.h"
# include "errors.h"
# include "execution.h"
# include "gcollector.h"
# include "history.h"
# include "shellutils.h"
# include "signals.h"
# include "utils.h"

/* READLINE INCLUDES */
# include <readline/history.h>
# include <readline/readline.h>

# ifndef DEBUG
#  define DEBUG 0
# endif

# ifndef OPEN_AST
#  define OPEN_AST 0
# endif

# define SHELL_NAME "minishell"
# define PROMPT BOLD " " SHELL_NAME " ➜ " RESET
# define PROMPT_SUCCESS CYAN "✅" PROMPT RESET
# define PROMPT_ERROR CYAN "❌" PROMPT RESET
# define PROMPT_DEFAULT CYAN "👋" PROMPT RESET
# define PROMPT_EXIT MOVEUP CLEARLINE PROMPT_DEFAULT "exit\n"

# define ANSI_HIDE "\033[8m"
# define ANSI_RESET "\033[0m"

# define HEREDOC_FILE "/tmp/.minishell_heredoc_"

typedef struct s_shell
{
	int			exit_code;
	char		**env;
	char		**exp;
	t_ast_node	*ast;
	char		*history_file;
	char		*heredoc_file;
	int			heredoc_index;
	bool		has_error;
}				t_shell;

#endif
