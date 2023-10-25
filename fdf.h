/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:03:52 by almarcos          #+#    #+#             */
/*   Updated: 2023/10/25 11:58:01 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

#define FDF_H

#include <MLX42/MLX42.h>
#include <libft.h>
#include <stdbool.h>

#define WIDTH 1000
#define HEIGHT 800

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_data;

typedef struct s_pixel
{
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct s_line_drawing_data
{
	int dx;
	int dy;
	int control;
	int incX;
	int incY;
} t_line_drawing_data;

void draw_line(t_data *data, t_pixel start, t_pixel end);

#endif
