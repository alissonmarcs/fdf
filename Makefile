# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 14:54:44 by almarcos          #+#    #+#              #
#    Updated: 2023/11/10 15:58:59 by almarcos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libs/Libft/libft.a
MLX42 = libs/MLX42/build/libmlx42.a
MLX42_FLAGS = -ldl -lglfw -pthread -lm
CFLAGS = -Wall -Werror -Wextra -g3 -O0
HEADERS = -I libs/Libft/ -I libs/MLX42/include/

MANDATORY_FOLDER = ./mandatory/
MANDATORY_SOURCES = $(addprefix $(MANDATORY_FOLDER), main.c parse_map.c \
	parse_map_utils.c draw_line.c draw_line_utils.c render.c render_utils.c \
	inits.c handling_errors.c)

OBJECTS_FOLDER = ./obj/
OBJECTS = $(subst mandatory,obj,$(MANDATORY_SOURCES:.c=.o))

all: $(OBJECTS_FOLDER) $(NAME)

$(OBJECTS_FOLDER):
	mkdir -p $(OBJECTS_FOLDER)

$(NAME): libs $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) $(MLX42_FLAGS) $(HEADERS) -o $@

libs: $(LIBFT) $(MLX42)

$(LIBFT):
	make -C libs/Libft/

$(MLX42):
	cd libs/MLX42/ && cmake -B build -DDEBUG=1
	cd libs/MLX42/ && cmake --build build -j4

$(OBJECTS_FOLDER)%.o: $(MANDATORY_FOLDER)%.c $(MANDATORY_FOLDER)fdf.h
	cc $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)*

fclean: clean
	rm -rf $(NAME)

clean_libs:
	make -C libs/Libft/ fclean
	rm -rf libs/MLX42/build

re: fclean all
