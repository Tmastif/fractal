# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilazar <ilazar@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 14:08:08 by ilazar            #+#    #+#              #
#    Updated: 2024/05/07 14:20:22 by ilazar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

# Sources
SRC_PATH := src/
SRC := main.c

# Minilibx
MLX_PATH := minilibx-Linux/
MLX_NAME := libmlx.a
MLX 	:= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH := libft
LIBFT_NAME := libft.a
LIBFT := $(LIBFT_PATH)$(LIBFT_NAME)


OBJS := $(SRCS:%.c=%.o)

INC_DIR := includes/\
		minilibx-linux/

HEADER := -I$(INC_DIR)

CC := cc

FLAGS := -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a .
	mv libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) -c $(FLAGS) $(HEADER) $< -o $@

clean: 
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
