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


# ------------  PROJECT  ----------------------------------------------------- #
NAME	=		libftprintf.a

# ------------  DIRECTORIES  ------------------------------------------------- #
SRC_DIR	=		libftprintf
HDR_DIR	=		includes
OBJ_DIR	=		objs
LIBFT_DIR =		libft
FT_PRINTF_DIR =	ft_printf

# ------------  SOURCE FILES  ------------------------------------------------ #

SRC_FLS	=		$(LIBFT_FLS)\
				$(FT_PRINTF_FLS)\

LIBFT_FLS = $(addprefix $(LIBFT_DIR)/,ft_atoi.c ft_bzero.c ft_calloc.c \
	ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
	ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c)

FT_PRINTF_FLS = $(addprefix $(FT_PRINTF_DIR)/,ft_cntdigits.c ft_format_ptrhex.c \
	ft_format_spec.c ft_printf.c)


# ------------  FILEPATHS  --------------------------------------------------- #
SRCS	=		$(addprefix $(SRC_DIR)/, $(SRC_FLS))
OBJS	=		$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
DEPS	=		$(OBJS:.o=.d)

# ------------  FLAGS  ------------------------------------------------------- #
CC		=		cc
RM		=		rm -rf
CFLGS	=		-Wall -Werror -Wextra
IFLGS	=		-I $(HDR_DIR)
DFLGS	=		-MMD -MP -O1

# ------------  RULES  ------------------------------------------------------- #
all: $(NAME)

-include $(DEPS)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLGS) $(DFLGS) -c -o $@ $< $(IFLGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(LIBFT_DIR)
	mkdir -p $(OBJ_DIR)/$(FT_PRINTF_DIR)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
