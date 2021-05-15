# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xchalle <xchalle@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 11:47:32 by xchalle           #+#    #+#              #
#    Updated: 2021/04/17 15:42:07 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	libft/get_next_line.c \
		libft/get_next_line_utils.c \
		libft/ft_strlen.c \
		libft/ft_strdup.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_strchr.c \
		libft/ft_strjoin.c \
		libft/ft_atoi.c \
		libft/ft_printf2.c \
		libft/ft_memcmp.c \
		libft/ft_strncmp.c \
		src/main.c \
		src/move.c \
		src/draw.c \
		src/hitwall.c \
		src/verif.c \
		src/check_setting.c \
		src/check_setting2.c \
		src/raycast_hor.c \
		src/raycast_ver.c \
		src/read_setting.c \
		src/arg_check.c \
		src/save.c \
		src/keybind.c \
		src/ft_mlx.c \
		src/init_player.c \
		src/summon_minimap.c \
		src/summon_minimap2.c \
		src/summon_struct.c \
		src/summon_struct2.c \
		src/summon_struct3.c \
		src/wall_img.c \
		src/pourcent_wall.c \

NAME = cub3D
CFLAGS = -Wall -Werror -Wextra -g -I./include -I./mlx
CC = gcc $(CFLAGS)
OBJ = $(SRC:.c=.o)

all:	mlx $(NAME)

$(%.o): $(%.c)
	$(CC) -o $@ -c $^

$(NAME): $(OBJ)
		make -C mlx/
		$(CC) -o $@ $^ -Lmlx/ -lmlx -lXext -lX11 -lm 	

clean:
		rm -f $(OBJ)
		make -C mlx/ clean

fclean: clean
		rm -f $(NAME)
		make -C mlx/ clean

re: fclean all

.PHONY: clean fclean all re
