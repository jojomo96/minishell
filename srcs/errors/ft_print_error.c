/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:58:07 by flfische          #+#    #+#             */
/*   Updated: 2024/05/24 19:14:26 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_putstrcolon_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putstr_fd(": ", fd);
}

/**
 * @brief Prints an error message to STDERR_FILENO.
 *
 * The error message is formatted as: SHELL_NAME: arg1: arg2: error
 *
 * @param error The error code.
 * @param arg1 The first path argument to print (optional).
 * @param arg2 The second path argument to print (optional).
 *
 * @note To retrieve the error message, you can use the `strerror` function.
 * For example, you can use `strerror(errno)` to get the error message
 * corresponding to the current value of `errno`.
 */
void	ft_print_error(char *error, char *arg1, char *arg2)
{
	ft_putstrcolon_fd(SHELL_NAME, STDERR_FILENO);
	if (arg1)
		ft_putstrcolon_fd(arg1, STDERR_FILENO);
	if (arg2)
		ft_putstrcolon_fd(arg2, STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
}

/**
 * @brief works like `ft_print_error`,
 * but for env errors: prints `key' instead of just key
 */
void	ft_print_error_env(char *error, char *arg1, char *key)
{
	ft_putstrcolon_fd(SHELL_NAME, STDERR_FILENO);
	if (arg1)
		ft_putstrcolon_fd(arg1, STDERR_FILENO);
	if (key)
	{
		ft_putstr_fd("`", STDERR_FILENO);
		ft_putstr_fd(key, STDERR_FILENO);
		ft_putstr_fd("': ", STDERR_FILENO);
	}
	ft_putendl_fd(error, STDERR_FILENO);
}

void	ft_print_syntax_error(char *arg)
{
	if (ft_get_shell()->has_error)
		return ;
	ft_putstrcolon_fd(SHELL_NAME, STDERR_FILENO);
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("'\n", STDERR_FILENO);
	if (arg[0] == ')' || arg[0] == '(')
		ft_get_shell()->exit_code = 2;
	else
		ft_get_shell()->exit_code = 1;
	ft_get_shell()->has_error = true;
}
