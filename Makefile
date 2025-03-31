# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luiza <luiza@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 19:42:06 by luiza             #+#    #+#              #
#    Updated: 2025/03/31 20:19:12 by luiza            ###   ########.fr        #
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
INC_DIR	= include/
LIB_DIR = libft/
MLX_DIR = minilibx-linux
OBJ_DIR	= obj/

# mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz

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

all: git_submodule $(LIBFT) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(COMP_OBJS)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	mkdir -p $(BIN_DIR)
	$(COMP)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR) all

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

git_submodule:
	git submodule update --init --recursive

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(BIN_DIR)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
