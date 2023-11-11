/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:03:52 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/11 10:43:45 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define VERTICAL_ROTATION_ANGLE 0.2
# define HORIZONTAL_ROTATION_ANGLE 0.2

// test only
# include <stdio.h>

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	uint32_t	color;
}				t_point;

typedef struct s_map
{
	t_point		**matrix;
	int			width;
	int			height;
	float		z_max;
}				t_map;

typedef struct s_cam
{
	float		scale;
	float		x_offset;
	float		y_offset;
	float		z_scale;
}				t_cam;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	t_cam		*cam;
}				t_fdf;

typedef struct s_line_drawing_data
{
	int			dx;
	int			dy;
	int			control;
	int			inc_x;
	int			inc_y;
}				t_line_drawing_data;

// map parsing
t_map			*parse_map(t_fdf *fdf, char *map_name);
int				validade_lines(int fd, int size);
void			validate_map_name(char *map_name);
void			center_to_origin(t_map *map);
void			clear_invalid_map(t_fdf *fdf, t_map *map);
t_point			**alloc_matrix(int width, int height);
void			free_matrix(t_map *map);
void			free_split(char **split_line);

// error managment
void			error_handler(short exit_status);

// inits
t_fdf			*init_fdf(char *map_name);
t_map			*init_map(void);
t_cam			*init_cam(t_fdf *fdf);
void			init_line_data(t_line_drawing_data *line_data, t_point start,
					t_point end);

// line drawing
void			put_pixel(t_fdf *fdf, uint32_t x, uint32_t y, uint32_t color);
void			draw_line(t_fdf *data, t_point start, t_point end);

// utils
uint32_t		put_alpha(uint32_t color);
float			get_scale(t_fdf *fdf);
void			set_background(t_fdf *fdf);

// rendering
void			render(t_fdf *fdf);
void			transformations(t_fdf *fdf, t_point start, t_point end);
void			scale(t_fdf *fdf, t_point *start, t_point *end);
void			isometric(t_fdf *fdf, t_point *start, t_point *end);
void			centralize(t_fdf *fdf, t_point *start, t_point *end);

// hook
void			hook(void *param);
#endif
