/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:49:37 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/08 21:38:21 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_count_substr(char const *s, char del)
{
	size_t	count;
	size_t	i;
	int		was_del;

	i = 0;
	count = 0;
	was_del = 1;
	while (s[i])
	{
		if (s[i] != del)
		{
			if (was_del)
				count++;
			was_del = 0;
		}
		else
			was_del = 1;
		i++;
	}
	return (count);
}

static char	**ft_split_args(char *content)
{
	char	**args;
	int		start;
	int		end;
	char	quote_type;
	int		i;

	start = 0;
	end = 0;
	args = (char **)ft_malloc(sizeof(char *) * ft_count_substr(content, ' ')
			+ 1);
	if (args == NULL)
		return (NULL); // TODO: handle error
	args[0] = NULL;
	i = 0;
	while (*content)
	{
		if (*content == '\'' || *content == '\"')
		{
			quote_type = *content;
			while (*content && *content != quote_type)
				content++;
		}
	}
}
