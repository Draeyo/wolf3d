NAME = wolf3d

SRCS_PATH = ./srcs/

INC_PATH = ./includes/

MLX_PATH = ./minilibx_macos/

LIBFT_PATH = ./libft/

SRCS_NAME = main.c

LIBFT_NAME = -lft

LIBFT = $(LIBFT_PATH) $(LIBFT_NAME)

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJ = $(SRCS:.c=.o)

MLX = $(MLX_PATH) -lmlx -lm

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB_FLAGS = -L$(MLX) -L $(LIBFT) -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@(make -C $(LIBFT_PATH))
	@(make -C $(MLX_PATH))
	@($(CC) -o $(NAME) $(OBJ) $(LIB_FLAGS))
	@(echo "\x1b[1;34m$(NAME)\x1b[0m \x1b[32mcreated.\x1b[0m \x1b[1;32m✓\x1b[0m")

%.o: %.c
	@($(CC) -o $@ -c $< $(CFLAGS) -I $(INC_PATH))

clean:
	@(make -C $(LIBFT_PATH) clean)
	@(make -C $(MLX_PATH) clean)
	@(/bin/rm -f $(OBJ))
	@(echo "\x1b[1;34m$(NAME)\x1b[0m object files \x1b[31mdeleted.\x1b[0m \x1b[1;32m✓\x1b[0m")

fclean: clean
	@(make -C $(LIBFT_PATH) fclean)
	@(/bin/rm -f $(NAME))
	@(echo "\x1b[1;34m$(NAME)\x1b[0m \x1b[31mdeleted.\x1b[0m \x1b[1;32m✓\x1b[0m")

re: fclean all
