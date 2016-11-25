# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlistrat <vlistrat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 14:06:50 by vlistrat          #+#    #+#              #
#    Updated: 2016/11/25 07:38:41 by vlistrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

INC = ./includes/

MLX_PATH = ./minilibx_macos/

LIBFT_PATH = ./libft/

SRCS_NAME =  main.c wolf3d.c map.c initialisation.c ft_calc.c \
	echap.c press.c release_key.c put_pixel.c move.c \
	complete_map.c expose.c

SRCS_PATH = ./srcs/

SRCS = $(addprefix $(SRCS_PATH),$(SRCS_NAME))

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lm -framework OpenGL -framework AppKit

BL = \x1b[0m
RED = \x1b[31m
HRED = \x1b[1;31m
GREEN = \x1b[32m
HGREEN = \x1b[1;32m
HPURPLE = \x1b[1;34m

all: $(NAME)

$(NAME): $(OBJ)
	@(make -C $(LIBFT_PATH))
	@(make -C $(MLX_PATH))
	@($(CC) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) $(MLX_FLAGS))
	@(echo "$(HPURPLE)$(NAME)$(BL) $(GREEN)created.$(BL) $(HGREEN)✓$(BL)")

%.o: %.c
	@($(CC) -o $@ -c $< -I $(INC) -I ./minilibx_macos/)

clean:
	@(make -C $(LIBFT_PATH) clean)
	@(make -C $(MLX_PATH) clean)
	@(/bin/rm -f $(OBJ))
	@(echo "$(HPURPLE)$(NAME)$(BL) object files $(RED)deleted.$(BL) $(HGREEN)✓$(BL)")

fclean: clean
	@(make -C $(LIBFT_PATH) fclean)
	@(/bin/rm -f $(NAME))
	@(echo "$(HPURPLE)$(NAME)$(BL) $(RED)deleted.$(BL) $(HGREEN)✓$(BL)")

re: fclean all
