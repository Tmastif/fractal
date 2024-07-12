NAME	= fractol

# directories
SRCDIR	= ./srcs
INCDIR	= ./includes
OBJDIR	= ./obj

# src / obj files
SRC		= main.c events.c render_utils.c string_utils.c fractal.c errors.c

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= cc
CFLAGS	= -Wall -Wextra -Werror


# mlx library
	MLX		= ./libs/mlx_linux/
	MLX_LNK	= -L $(MLX) -l mlx -lXext -lX11

##MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# ft library
FT		= ./libs
FT_LIB	= $(addprefix $(FT)/,libftprintf.a)
FT_INC	= -I ./libs/includes
FT_LNK	= -L ./libs/includes

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	#$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) $(FT_LIB) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all
