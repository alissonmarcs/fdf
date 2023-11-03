# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:54:44 by almarcos          #+#    #+#              #
#    Updated: 2023/11/03 10:33:41 by almarcos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libs/Libft/libft.a
MLX42 = libs/MLX42/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Werror -Wextra -g -O0
HEADERS = -I libs/Libft/ -I libs/MLX42/include/

SOURCES = main.c error_handler.c parse_map.c parse_map_utils.c inits.c draw_line.c \
	utils.c

all: $(NAME)

$(NAME):
	cc $(SOURCES) $(LIBFT) $(MLX42) $(MLX42_FLAGS) $(HEADERS) -g3 -O0

libs: $(LIBFT) $(MLX42)

$(LIBFT):
	make -C libs/Libft/

$(MLX42):
	cd libs/MLX42/ && cmake -B build -DDEBUG=1
	cd libs/MLX42/ && cmake --build build -j4

clean:
	make -C libs/Libft/ fclean
	rm -rf libs/MLX42/build

run: libs
	@cc $(SOURCES) $(LIBFT) $(MLX42) $(MLX42_FLAGS) $(HEADERS) -g3 -O0
	./a.out
