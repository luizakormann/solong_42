# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 19:42:06 by luiza             #+#    #+#              #
#    Updated: 2025/04/11 21:44:08 by lukorman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               configuration                                  #
# **************************************************************************** #

# common comp
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I$(LIB_DIR)/include
CFLAGS += $(MLX_INC)
LDFLAGS += $(MLX_FLAGS)
RM	= rm -rf

# link libft
LIBFT = $(LIB_DIR)/bin/libft.a
FINDLIBFT = -L$(LIB_DIR)/bin
LINKLIB = -lft

# **************************************************************************** #
#                                directories                                   #
# **************************************************************************** #

# common
INC_DIR	= include
LIB_DIR = libft
MLX_DIR = MLX42
OBJ_DIR	= obj

# mlx
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_INC = -I $(MLX_DIR)/include
MLX_FLAGS = -L$(MLX_DIR)-ldl -lglfw -pthread -lm
MLX_SRC = $(shell find .src -iname "*.c")
MLX_OBJ = ${MLX_SRC:.c=.o}

# mandatory
SRC_DIR	= src/
OBJ_DIR	= obj/
BIN_DIR	= bin/

# **************************************************************************** #
#                                   files                                      #
# **************************************************************************** #

# header
HEADERS = $(shell find $(INC_DIR) -name '*.h')

# executable mandatory
NAME	= $(BIN_DIR)so_long

# sources
SRC	= $(shell find $(SRC_DIR) -name '*.c')

# objects
OBJS = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))

# **************************************************************************** #
#                              compile commands                                #
# **************************************************************************** #

COMP_OBJS	= $(CC) $(CFLAGS) -c $< -o $@
COMP	= $(CC) $(CFLAGS) $(OBJS) $(FINDLIBFT) $(LINKLIB) -o $(NAME)

# **************************************************************************** #
#                                  targets                                     #
# **************************************************************************** #

all: mlx git_submodule $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(COMP_OBJS)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	mkdir -p $(BIN_DIR)
	$(COMP)

LEAKS	:=	valgrind --leak-check=full --show-leak-kinds=all

$(LIBFT):
	$(MAKE) -C $(LIB_DIR) all

valgrind: all
	@$(LEAKS)

git_submodule:
	git submodule update --init --recursive

mlx:
	sed -i "s/(VERSION 3.18.0)/(VERSION 3.16.0)/" ./MLX42/CMakeLists.txt
	@cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(BIN_DIR)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re git_submodule mlx valgrind
