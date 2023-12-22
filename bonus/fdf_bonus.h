/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:27:26 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/23 10:55:21 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H

# define FDF_BONUS_H

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>

# define WINDOW_WIDTH 1300
# define WINDOW_HEIGHT 900
# define ONE_DEGREE_IN_RADIUS 0.01745329
# define X_AXIS_ANGLE_ROTATION_RADIUS 0.610865
# define Z_AXIS_ANGLE_ROTATION_RADIUS 0.785398

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
	short		projection;
	float		scale;
	float		x_offset;
	float		y_offset;
	float		z_scale_default;
	float		z_scale_factor;
	float		rotation_angle_x;
	float		rotation_angle_y;
	float		rotation_angle_z;
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
	short		dx;
	short		dy;
	short		control;
	short		inc_x;
	short		inc_y;
}				t_line_drawing_data;

enum			e_projection
{
	ISOMETRIC,
	TOP_VIEW
};

/* parse_map_bonus.c, parse_map_utils_bonus.c */
t_map			*parse_map(t_fdf *fdf, char *map_name);
int				validade_lines(int fd, int size);
uint32_t		put_alpha(uint32_t color);
float			get_scale(t_fdf *fdf);
void			center_to_origin(t_map *map);
void			validate_map_file(char *map_name);

/* news_bonus.c */
t_fdf			*new_fdf(char *map_name);
t_map			*new_map(void);
t_cam			*new_camera(t_fdf *fdf);
void			set_camera(t_fdf *fdf, short PROJECTION);
void			new_line_data(t_line_drawing_data *line_data, t_point *start,
					t_point *end);

/* draw_line_bonus.c, draw_line_utils_bonus.c */
void			draw_line(t_fdf *data, t_point start, t_point end);
void			put_pixel(t_fdf *fdf, int x, int y, uint32_t color);

/* render_bonus.c, render__utils_bonus.c */
void			render(void *param);
void			set_background(t_fdf *fdf);

/* error_handler_bonus.c */
void			error_handler(short exit_status);

/* others_utils_bonus.c */
void			clear_invalid_map(t_fdf *fdf, t_map *map);
t_point			**alloc_matrix(int width, int height);
void			free_matrix(t_map *map);
void			free_all(t_fdf *fdf);

/* key_press_handler_bonus.c, key_press_handler_utils_bonus.c */
void			key_press_handler(void *param);
void			zoom(t_fdf *fdf);
void			toggle_projection(t_fdf *fdf);

/* rotations_bonus.c */
void			rotate_x(t_fdf *fdf, t_point *start, t_point *end, float angle);
void			rotate_y(t_point *start, t_point *end, float angle);
void			rotate_z(t_point *start, t_point *end, float angle);
#endif
