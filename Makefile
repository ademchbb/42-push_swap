# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adchebbi <adchebbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/26 07:30:00 by adchebbi          #+#    #+#              #
#    Updated: 2026/03/26 07:44:51 by adchebbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************** PROGRAM **************** #
#                                           #
NAME        = push_swap
#                                           #
# ***************************************** #


# **************** COMPILER *************** #
#                                           #
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
#                                           #
# ***************************************** #


# ************* DIRECTORIES *************** #
#                                           #
SRC_DIR     = src
OPS_DIR     = $(SRC_DIR)/operations
PARSE_DIR   = $(SRC_DIR)/parsing
SORT_DIR    = $(SRC_DIR)/sorting
UTILS_DIR   = $(SRC_DIR)/utils
INC_DIR     = include
LIBFT_DIR   = libft
#                                           #
# ***************************************** #


# **************** FILES ****************** #
#                                           #
SRCS        = $(SRC_DIR)/main.c \
              $(OPS_DIR)/swap.c \
              $(OPS_DIR)/push.c \
              $(OPS_DIR)/rotate.c \
              $(OPS_DIR)/reverse_rotate.c \
              $(PARSE_DIR)/parsing.c \
              $(SORT_DIR)/sort_small.c \
              $(SORT_DIR)/sort_big.c \
              $(SORT_DIR)/sort.c \
              $(SORT_DIR)/target.c \
              $(SORT_DIR)/cost.c \
              $(SORT_DIR)/indexing.c \
              $(UTILS_DIR)/utils.c \
              $(UTILS_DIR)/stack_utils.c
#                                           #
OBJS        = $(SRCS:.c=.o)
#                                           #
LIBFT       = $(LIBFT_DIR)/libft.a
#                                           #
# ***************************************** #


# **************** COLORS ***************** #
#                                           #
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
RED         = \033[0;31m
BLUE        = \033[0;34m
RESET       = \033[0m
#                                           #
# ***************************************** #


# **************** RULES ****************** #
#                                           #
all: $(LIBFT) $(NAME)
#                                           #
$(LIBFT):
	@printf "$(YELLOW)📚 Compiling libft...$(RESET)\n"
	@make -C $(LIBFT_DIR) --silent
	@printf "$(GREEN)✅ Libft ready$(RESET)\n"
#                                           #
$(NAME): $(OBJS) $(LIBFT)
	@printf "$(BLUE)🔧 Linking $(NAME)...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "$(GREEN)✅ $(NAME) compiled successfully$(RESET)\n"
#                                           #
%.o: %.c
	@printf "$(YELLOW)🔨 Compiling $<$(RESET)\n"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@
#                                           #
clean:
	@printf "$(RED)🧹 Cleaning object files$(RESET)\n"
	@make clean -C $(LIBFT_DIR) --silent
	@$(RM) $(OBJS)
#                                           #
fclean: clean
	@printf "$(RED)🧼 Full clean$(RESET)\n"
	@make fclean -C $(LIBFT_DIR) --silent
	@$(RM) $(NAME)
	@sleep 1
	@clear
#                                           #
re: fclean all
#                                           #
.PHONY: all clean fclean re
#                                           #
# ***************************************** #