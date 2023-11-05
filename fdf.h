/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:03:52 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/05 16:26:03 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

#define FDF_H

#include <MLX42/MLX42.h>
#include <libft.h>
#include <stdbool.h>
#include <stdint.h>
#include <fcntl.h>
#include <math.h>

#define VERTICAL_ROTATION_ANGLE 0.8
#define HORIZONTAL_ROTATION_ANGLE 0.8

// test only
#include <stdio.h>

#define WINDOW_WIDTH 1300
#define WINDOW_HEIGHT 900

typedef struct s_point
{
	float x;
	float y;
	float z;
	uint32_t color;
} t_point;

typedef struct s_map
{
	t_point **matrix;
	int width;
	int height;
} t_map;

typedef struct s_cam
{
	float scale;
	float x_offset;
	float y_offset;
	float x_percent;
	float y_percent;
} t_cam;


typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map *map;
	t_cam *cam;
}				t_fdf;

typedef struct s_line_drawing_data
{
	int dx;
	int dy;
	int control;
	int incX;
	int incY;
} t_line_drawing_data;

// map parsing
t_map	*parse_map(t_fdf *fdf, char *map_name);
int	validade_lines(int fd, int size);
void clear_map(t_fdf *fdf, t_map *map);
t_point **alloc_matrix(int width, int height);
void free_matrix(t_map *map);
void free_split(char **split_line);

// error managment
void error_handler(short exit_status);

// inits
t_fdf *init_fdf(char *map_name);
t_map *init_map(void);
t_cam *init_cam(t_fdf *fdf);

// line drawing
void draw_line(t_fdf *data, t_point start, t_point end);
uint32_t put_alpha(uint32_t color);
float get_scale(t_fdf *fdf);
#endif
