/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:15:29 by jmoritz           #+#    #+#             */
/*   Updated: 2024/05/26 18:06:52 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# define TOKEN_BUFFER_SIZE 64

typedef struct s_ast_node		t_ast_node;

typedef enum e_ast_node_type
{
	AST_TYPE_LEAF,
	AST_TYPE_NODE,
	AST_TYPE_PARANTHESIS
}								t_ast_node_type;

typedef enum e_ast_paranthesis
{
	AST_PARANTHESIS_OPEN,
	AST_PARANTHESIS_CLOSE
}								t_ast_paranthesis;

typedef enum e_operation_type
{
	OP_REDIRECT_IN,
	OP_REDIRECT_OUT,
	OP_APPEND_OUT,
	OP_HEREDOC,
	OP_PIPE,
	OP_AND,
	OP_OR
}								t_operation_type;

typedef struct s_ast_leaf
{
	char						**argv;
	int							fd_in;
	int							fd_out;
	bool						fd_from_pipe;
	pid_t						pid;
	char						*heredoc_filename;
}								t_ast_leaf;

struct							s_ast_node
{
	t_ast_node_type				type;
	int							exit_status;
	bool						is_subshell;
	union
	{
		t_ast_leaf				leaf;
		struct
		{
			t_operation_type	op_type;
			t_ast_node			*left;
			t_ast_node			*right;
		} s_node;
		t_ast_paranthesis		type;
	} u_data;
};

t_ast_node						*ft_ast_new_node(const char *input,
									size_t start, size_t value_length);
void							ft_ast_free_node(t_ast_node *node);

t_ast_node						**ft_tokenize_input(char *input);
void							build_ast(t_ast_node **ast, t_ast_node **nodes,
									bool last_was_subshell);
int								find_max_precedence_index(t_ast_node **nodes,
									int *is_in_parenthesis);

// utils
const char						*op_type_to_string(t_operation_type op_type);
void							write_ast_to_dot_file(t_ast_node *root);
char							**ft_split_args(char *content);

// operations
void							ft_ast_move_arguments(t_ast_node *node);
void							fr_traverse_and_process(t_ast_node *node,
									t_ast_node_type node_type,
									void (*process)(t_ast_node *));
void							ft_expand_arguments(t_ast_node *node);
void							ft_remove_outer_quotes_in_array(char ***arr);
void							ft_toggle_quotes(char *arr, bool *in_s_quotes,
									bool *in_d_quotes);
void							ft_expand_wildcard(char **arr);
int								ft_match_pattern(const char *filename,
									const char *pattern);
bool							ft_ast_validate(t_ast_node *node);
bool							ft_traverse_process_return(t_ast_node *root,
									t_ast_node_type node_type,
									bool (*process)(t_ast_node *));
bool							is_delimiter(char c);
void							remove_outer_quotes(char **arr);
void							ft_handle_env_variable(char **str_ptr,
									bool in_d_quotes, bool is_last_arg);
void							encase_outer_quotes(char **arr);
void							ft_encase_outer_quotes_in_array(char **arr);
char							*ft_dupe_quotes(char *str);

#endif
