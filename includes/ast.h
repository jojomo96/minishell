#ifndef FT_AST_H
# define FT_AST_H

# define TOKEN_BUFFER_SIZE 1

typedef enum
{
	NODE_ARGUMENT,
	NODE_PIPE,
	NODE_REDIRECT_IN,
	NODE_REDIRECT_OUT,
	NODE_APPEND_OUT,
	NODE_HEREDOC,
	NODE_SUBSHELL,
	NODE_AND,
	NODE_OR,
}						e_token_type;

typedef struct s_token
{
	e_token_type		type;
	char				*content;
}						t_token;

typedef struct s_ast_node
{
	e_token_type		type;
	char				*content;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}						t_ast_node;

t_token					**ft_tokenize_input(char *input);
t_token					*ft_token_new(const char *input, size_t start,
							size_t token_length);
void					ft_tokens_free(t_token **tokens);
void					ft_token_free(t_token *token);

#endif
