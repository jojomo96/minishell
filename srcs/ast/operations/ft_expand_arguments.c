/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 09:54:50 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/23 17:57:50 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Function to split a string by spaces and add the parts to the result array
void	split_and_add(char *str, char **result, int *index)
{
	char	*start;
	char	*end;
	bool	in_s_quotes;
	bool	in_d_quotes;

	in_s_quotes = false;
	in_d_quotes = false;
	start = str;
	while (*start != '\0')
	{
		while (*start == ' ')
			start++;
		if (*start == '\0')
			break;
		end = start;
		while (*end != '\0')
		{
			ft_toggle_quotes(end, &in_s_quotes, &in_d_quotes);
			if (!in_s_quotes && !in_d_quotes && ft_isspace(*end))
				break ;
			end++;
		}
		if (*end == '\0')
		{
			result[(*index)++] = start;
			break ;
		}
		*end = '\0';
		result[(*index)++] = start;
		start = end + 1;
	}
}
int	determine_size(char **array)
{
	int	size;

	size = 0;
	while (array[size] != NULL)
	{
		size++;
	}
	return (size);
}

// Function to process the array of char * and replace it with a new one
void	process_array(char ***array)
{
	int		i;
	int		index;
	int		size;
	char	**result;

	i = 0;
	index = 0;
	size = determine_size(*array);
	result = (char **)ft_malloc(size * 10 * sizeof(char *));
	if (!result)
	{
		perror("Failed to allocate memory");
		return ;
	}
	while (i < size)
	{
		split_and_add((*array)[i], result, &index);
		i++;
	}
	result[index] = NULL;
	*array = result;
}

bool	isDelimiter(char c)
{
	return (!ft_isalnum(c) && c != '_' && c != '*' && c != '.');
	// maybe remove .
}

static void	ft_handle_env_variable(char **str_ptr, bool in_d_quotes,
		bool is_last_arg)
{
	char	*str;
	char	*new_value;

	if (str_ptr == NULL || *str_ptr == NULL)
		return ;
	str = *str_ptr;
	if (str[1] == '\0' && !in_d_quotes && !is_last_arg)
		new_value = ft_strdup("");
	else if (str[1] == '\0' && (in_d_quotes || is_last_arg))
		new_value = ft_strdup("$");
	else if (str[1] == '?')
		new_value = ft_itoa(ft_get_shell()->exit_code);
	else
		new_value = ft_fetch_env_var(str + 1);
	free(str);
	if (new_value != NULL)
		*str_ptr = new_value;
	else
		*str_ptr = ft_strdup("");
}

static void	ft_expand_splited_args(char **splited_args)
{
	int		i;
	bool	in_s_quotes;
	bool	in_d_quotes;

	in_s_quotes = false;
	in_d_quotes = false;
	i = 0;
	while (splited_args[i])
	{
		ft_toggle_quotes(splited_args[i], &in_s_quotes, &in_d_quotes);
		if (splited_args[i][0] == '$' && !in_s_quotes)
			ft_handle_env_variable(&splited_args[i], in_d_quotes, splited_args[i
				+ 1] == NULL);
		else if (splited_args[i][0] == '~' && !in_s_quotes && !in_d_quotes
			&& splited_args[i][1] == '\0')
		{
			free(splited_args[i]);
			splited_args[i] = ft_fetch_env_var("HOME");
		}
		i++;
	}
	i = 0;
	while (splited_args[i] && ft_strnstr(splited_args[i], "*",
			ft_strlen(splited_args[i])) != NULL)
		expand_wildcard(&splited_args[i++]);
}

static char	**ft_expand_arguments_in_strarr(char **arr)
{
	char	**splited_args;
	int		i;

	i = 0;
	while (arr[i])
	{
		splited_args = ft_split_on_delim(arr[i], &isDelimiter);
		debug_print_strarr(splited_args);
		ft_expand_splited_args(splited_args);
		ft_free(arr[i]);
		arr[i] = ft_strarr_join(splited_args);
		debug_message_1("Expanded argument: ", arr[i]);
		i++;
	}
	process_array(&arr);
	i = 0;
	while (arr[i]!=NULL)
	{
		splited_args = ft_split_on_delim(arr[i], &isDelimiter);
		ft_remove_outer_quotes(splited_args);
		arr[i] = ft_strarr_join(splited_args);
		i++;
	}
	return (arr);
}

void	ft_expand_arguments(t_ast_node *node)
{
	if (node->type != AST_TYPE_LEAF)
		return ;
	if (node->u_data.leaf.argv == NULL)
		return ;
	node->u_data.leaf.argv = ft_expand_arguments_in_strarr(node->u_data.leaf.argv);
}
