# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:59:27 by flfische          #+#    #+#              #
#    Updated: 2024/04/25 18:20:48 by flfische         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast
NAME := minishell
# DIRECTORIES
SRC_DIRS := srcs
OBJ_DIR := obj
INC_DIR := includes

# FILES
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIR)
CFILES := \
		minishell.c \

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

$(NAME): $(OFILES) $(HEADER)
#$(NAME): $(LIBFT) $(OFILES) $(HEADER)
	@echo "$(YELLOW)Compiling $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) -o $@ $(OFILES)
#	@$(CC) $(CFLAGS) -o $@ $(OFILES) $(LIBFT_FLAGS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ 

$(OBJ_DIR):
	@echo "$(YELLOW)Creating obj directory...$(NC)"
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(NC)"
	if [ ! -d $(LIBFT_DIR) ]; then mkdir -p $(LIBFT_DIR); fi
	@git submodule update --init --recursive
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "$(RED)Removing object files...$(NC)"
	@rm -rf $(OBJ_DIR)
#	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Removing binary files...$(NC)"
	@rm -f $(NAME)
#	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

norm:
	norminette $(SRC_DIRS) $(INC_DIR) $(LIBFT_DIR)

.PHONY: all clean fclean re norm ascii

# colors:
RED = \033[0;31m
YELLOW = \033[0;33m
NC = \033[0m
CYAN = \033[0;36m

# decoration:
ascii:
	@echo "$(CYAN)"
	@echo "           __     __       "
	@echo "|\/|||\ ||(_ |__||_ |  |   "
	@echo "|  ||| \||__)|  ||__|__|__ "
	@echo "                           "
	@echo "$(NC)"
