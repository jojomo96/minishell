#include "minishell.h"

e_token_type ft_get_token_type(char *token_content)
{
    if (ft_strcmp(token_content, "<") == 0)
        return NODE_REDIRECT_IN;
    if (ft_strcmp(token_content, ">") == 0)
        return NODE_REDIRECT_OUT;
    if (ft_strcmp(token_content, ">>") == 0)
        return NODE_APPEND_OUT;
    if (ft_strcmp(token_content, "<<") == 0)
        return NODE_HEREDOC;
    if (ft_strcmp(token_content, "&&") == 0)
        return NODE_AND;
    if (ft_strcmp(token_content, "|") == 0)
        return NODE_PIPE;
    if (ft_strcmp(token_content, "||") == 0)
        return NODE_OR;
    if (ft_strcmp(token_content, "(") == 0)
        return NODE_SUBSHELL;
    if (ft_strcmp(token_content, ")") == 0)
        return NODE_SUBSHELL;
    return NODE_ARGUMENT;
}

t_token *ft_token_new(const char *input, size_t start, size_t token_length) {
    t_token *token;
    char *token_content;

    token = (t_token *)ft_malloc(sizeof(t_token));
    if (!token)
        return (NULL); //TODO: handle error
    token_content = (char *)ft_malloc(sizeof(char) * (token_length + 1));
    if (!token_content) {
        free(token);
        return (NULL); //TODO: handle error
    }
    ft_strlcpy(token_content, input + start, token_length + 1);
    token->content = token_content;
    token->type = ft_get_token_type(token_content);
    return token;
}

void ft_extract_tokens(t_token **tokens, char *input, int *position, int *token_count)
{
    int start;
    int end;
    int token_length;

    start = *position;
    end = *position;
    token_length = 0;
    while(input[end] && !ft_isspace(input[end]))
    {
        end++;
        token_length++;
    }
    tokens[*token_count] = ft_token_new(input, start, token_length);
    (*token_count)++;
    *position = end;
}

t_token ** ft_tokenize_input(char *input)
{
    t_token **tokens;
    int position;
    int token_count;
    int input_length;

    input_length = ft_strlen(input);
    tokens = (t_token **)ft_malloc(sizeof(t_token *) * (input_length + 1));
    if(!tokens) //TODO: handle error
        return (NULL);
    position = 0;
    token_count = 0;
    while(position < input_length)
    {
        if(ft_isspace(input[position]))
        {
            position++;
            continue;
        }
        ft_extract_tokens(tokens, input, &position, &token_count);
    }
    tokens[token_count] = NULL;
    return (tokens);
}
