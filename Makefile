# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luiza <luiza@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 19:42:06 by luiza             #+#    #+#              #
#    Updated: 2025/03/31 19:58:12 by luiza            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               configuration                                  #
# **************************************************************************** #

# common comp
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I$(LIB_DIR)/include
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
OBJ_DIR	= obj/

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

$(NAME): $(LIBFT) $(OBJS)
	mkdir -p $(BIN_DIR)
	$(COMP)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR) all

git_submodule:
	git submodule update --init --recursive

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(BIN_DIR)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
