# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lukorman <lukorman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 19:42:06 by luiza             #+#    #+#              #
#    Updated: 2025/04/29 22:02:22 by lukorman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               configuration                                  #
# **************************************************************************** #

# common comp
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -rf

# **************************************************************************** #
#                                directories                                   #
# **************************************************************************** #

# common structure
INC_DIR	= include
SRC_DIR	= src/
OBJ_DIR	= obj/
BIN_DIR	= bin/
LIB_DIR = libft
MLX_DIR = MLX42


# **************************************************************************** #
#                                  ext libs                                    #
# **************************************************************************** #

# libft
LIBFT = $(LIB_DIR)/bin/libft.a
LIBFT_FLAGS = -L$(LIB_DIR)/bin -lft

# mlx
MLX_LIB = $(MLX_DIR)/build/libmlx42.a
MLX_INC = -I $(MLX_DIR)/include
MLX_FLAGS = -L$(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
MLX_SRC = $(shell find $(MLX_DIR)/src -name "*.c")
MLX_OBJ = ${MLX_SRC:.c=.o}

# **************************************************************************** #
#                                   files                                      #
# **************************************************************************** #

# executable
NAME	= $(BIN_DIR)so_long

# header
HEADERS = $(shell find $(INC_DIR) -name '*.h')

# sources
SRC	= $(shell find $(SRC_DIR) -name '*.c')

# objects
OBJS = $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRC:.c=.o))

# **************************************************************************** #
#                              compile commands                                #
# **************************************************************************** #

# comb flags
CFLAGS += -I$(LIB_DIR)/include $(MLX_INC)
LDFLAGS += $(MLX_FLAGS) $(LIBFT_FLAGS)

# comp
COMP_OBJS	= $(CC) $(CFLAGS) -c $< -o $@
COMP	= $(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

# **************************************************************************** #
#                                  targets                                     #
# **************************************************************************** #

all: git_submodule mlx $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	mkdir -p $(dir $@)
	$(COMP_OBJS)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	mkdir -p $(BIN_DIR)
	$(COMP)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR) all

MAP ?= maps/test.ber

SUP	:=	valgrind --leak-check=full --show-leak-kinds=all\
		--track-origins=yes --log-file=valgrind-out.txt --track-fds=yes\
		--suppressions=.supmlx.sup

supmlx: all
	@$(SUP) ./bin/so_long $(MAP)

git_submodule:
	git submodule update --init --recursive

mlx:
	sed -i "s/(VERSION 3.18.0)/(VERSION 3.16.0)/" ./MLX42/CMakeLists.txt
	@cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

clean:
	$(RM) $(OBJ_DIR)
	$(RM) valgrind-out.txt


fclean: clean
	$(RM) $(BIN_DIR)
	$(RM) valgrind-out.txt
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re git_submodule mlx supmlx
