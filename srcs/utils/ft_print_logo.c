/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_logo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:28:09 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 20:04:56 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_username(void)
{
	char	*username;

	username = ft_env_get(ft_get_shell()->env, "USER");
	if (username)
	{
		printf(BOLD GREEN);
		printf("\n👾 " ITALIC " Hello, %s" RESET BOLD "  👾\n", username);
		printf("\n");
		printf(RESET);
		ft_free(username);
	}
}

void	ft_print_logo(void)
{
	const char	*jmoritz = "https://github.com/jojomo96";
	const char	*flfische = "https://github.com/flomero";

	printf("\033[H\033[J");
	printf("\033[36m"
		"\n"
		"\n"
		"\n"
		"███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     \n"
		"████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     \n"
		"██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     \n"
		"██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     \n"
		"██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗\n"
		"╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝\n"
		"                                                                   \n"
		"                     Welcome to the Minishell!                     \n"
		"\033[0m" // Reset color
		"\n");
	printf("\033[36m\t\t\t\e]8;;%s\aflfische\e]8;;\a && \e]8;;%s\ajmoritz\e]8"
		";;\a\033[0m\n\n", flfische, jmoritz);
	print_username();
}
