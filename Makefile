# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:54:44 by almarcos          #+#    #+#              #
#    Updated: 2023/10/27 14:33:03 by almarcos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libs/Libft/libft.a
MLX42 = libs/MLX42/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Werror -Wextra -g -O0
HEADERS = -I libs/Libft/ -I libs/MLX42/include/

SOURCES = draw_line/draw_line.c parse_map/parse_map.c

all: run

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
	@cc main5.c $(SOURCES) $(LIBFT) $(MLX42) $(MLX42_FLAGS) $(HEADERS) -g -O0
	./a.out
