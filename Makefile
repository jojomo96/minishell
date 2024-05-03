# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:59:27 by flfische          #+#    #+#              #
#    Updated: 2024/04/28 17:19:40 by flfische         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
NAME := minishell
# DIRECTORIES
SRC_DIRS := srcs \
			srcs/builtins \
			srcs/utils \
			srcs/env \
			srcs/errors \
			srcs/gcollector \
			srcs/ast \


SRC_DIRS += srcs/debug

OBJ_DIR := obj
INC_DIR := includes

# FILES
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIR)
CFILES := \
		minishell.c \

# BUILTINS
CFILES += ft_pwd.c ft_env.c ft_cd.c

# ENVIRONMENT
CFILES += ft_env_index.c \
			ft_env_add.c \
			ft_env_change.c \
			ft_env_create_entry.c \
			ft_env_remove.c \
			ft_env_get.c \

# UTILS
CFILES += ft_strarr_cpy.c \
			ft_strarr_free.c

# ERRORS
CFILES += ft_print_error.c

# GCOLLECTOR
CFILES += ft_malloc.c \
			ft_free.c \
			ft_gc_add.c \
			ft_gc_freeall.c \
			ft_gc_set.c \
			ft_gc_get.c \

# AST
CFILES += ft_token.c \

# DEBUG
CFILES += debug_printgc.c

OFILES := $(addprefix $(OBJ_DIR)/, $(CFILES:.c=.o))
HEADER := $(INC_DIR)/minishell.h
INCLUDES := -I$(INC_DIR)

# LIBFT

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_FLAGS := -L$(LIBFT_DIR) -lft
INCLUDES += -I$(LIBFT_DIR)

# RULES
all: ascii $(NAME)

$(NAME): $(LIBFT) $(OFILES) $(HEADER)
	@printf "\n$(YELLOW)Compiling $(NAME)...$(NC)\n"
	@$(CC) $(CFLAGS) -o $@ $(OFILES) $(LIBFT_FLAGS)
	@if [ -f $(NAME) ]; then \
		echo "$(GREEN)$(NAME) compiled successfully!$(NC)"; \
		echo "$(CYAN)Run with ./$(NAME)$(NC)"; \
		echo "------------------------------------------------"; \
	else \
		echo "$(RED)$(NAME) failed to compile$(NC)"; \
	fi

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(eval CURRENT := $(shell echo $$(($(CURRENT) + 1))))
	@$(eval PERCENT := $(shell echo $$(($(CURRENT) * 100 / $(TOTAL_SRCS)))))
	@printf "$(CLEAR_LINE)$(YELLOW)Compiling $(PERCENT)%% [$(CURRENT)/$(TOTAL_SRCS)] $(ITALIC_LIGHT_YELLOW)$<$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(OBJ_DIR):
	@echo "$(YELLOW)Creating obj directory...$(NC)"
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(RED)Removing object files...$(NC)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Removing binary files...$(NC)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

norm:
	@norminette $(SRC_DIRS) $(INC_DIR) $(LIBFT_DIR) | grep "Error" || echo "$(GREEN)Norme OK$(NC)"

.PHONY: all clean fclean re norm ascii

# colors:
GREEN = \033[0;32m
LIGHT_GREEN = \033[0;92m
RED = \033[0;31m
YELLOW = \033[0;33m
LIGHT_YELLOW = \033[0;93m
ITALIC_LIGHT_YELLOW = \033[3;93m
CYAN = \033[0;36m
NC = \033[0m
CLEAR_LINE = \033[2K\r
ASCII_ART = $(CYAN)

# decoration:
ascii:
	@echo "------------------------------------------------"
	@echo "$(CYAN)"
	@echo "           __     __       "
	@echo "|\/|||\ ||(_ |__||_ |  |   "
	@echo "|  ||| \||__)|  ||__|__|__ "
	@echo "                           "
	@echo "$(NC)"

BAR_WIDTH = 50
TOTAL_SRCS = $(words $(CFILES))