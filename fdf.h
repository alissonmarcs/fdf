/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:03:52 by almarcos          #+#    #+#             */
/*   Updated: 2023/10/27 15:05:50 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

#define FDF_H

#include <MLX42/MLX42.h>
#include <libft.h>
#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>

#define WIDTH 1000
#define HEIGHT 700

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_data;

typedef struct s_pixel
{
	uint32_t			x;
	uint32_t			y;
	uint32_t			color;
}				t_pixel;

typedef struct s_line_drawing_data
{
	int dx;
	int dy;
	int control;
	int incX;
	int incY;
} t_line_drawing_data;

typedef struct s_point
{
	int x;
	int y;
	int z;
	uint32_t color;
} t_point;

typedef struct s_map
{
	t_list *list;
	t_point *points;
	uint32_t size;
} t_map;


void draw_line(t_data *data, t_pixel start, t_pixel end);
void parse_map(t_map *map, char *map_file);

#endif
