# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:54:44 by almarcos          #+#    #+#              #
#    Updated: 2023/10/17 15:36:21 by almarcos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libs/Libft/libft.a
MLX42 = libs/MLX42/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -pthread -lm
HEADERS = -I libs/Libft/ -I libs/MLX42/include/

all: run

libs: $(LIBFT) $(MLX42)

$(LIBFT):
	make -C libs/Libft/

$(MLX42):
	make -C libs/MLX42/build

run: libs
	cc main.c $(MLX42) $(MLX42_FLAGS) $(LIBFT) $(HEADERS)
	./a.out
