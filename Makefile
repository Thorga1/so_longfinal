# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thorgal <thorgal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:28:00 by tordner           #+#    #+#              #
#    Updated: 2025/01/18 15:44:03 by thorgal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OS = $(shell uname)

SRCS =  main.c      		\
        utils.c				\
        setup.c     		\
		check_rectangular.c \
        errors.c    		\
        ft_split.c  		\
		check_map.c			\
		map_handling.c		\
		mlx_handling.c		\
		sprite_handling.c		\
		map_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

ifeq ($(OS), Linux)
    MLX_PATH = ./mlx_linux
    MLX = $(MLX_PATH)/libmlx.a
    LIBS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
    CFLAGS = -g -Imlx_linux
else
    MLX_PATH = ./mlx
    MLX = $(MLX_PATH)/libmlx.a
    LIBS = -L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
    CFLAGS = -g  -Imlx
endif

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	$(MAKE)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_PATH)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re