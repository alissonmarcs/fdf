/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:32:54 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/20 11:06:19 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	put_alpha(uint32_t color)
{
	uint32_t		new_color;
	unsigned char	*ptr;

	new_color = color << 8;
	ptr = (unsigned char *)&new_color;
	*ptr = 255;
	return (new_color);
}

float	get_scale(t_fdf *fdf)
{
	float	scale;
	float	scale_x;
	float	scale_y;

	scale_x = WINDOW_WIDTH / (float)fdf->map->width;
	scale_y = WINDOW_HEIGHT / (float)fdf->map->height;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale / 1.55);
}

void	center_to_origin(t_map *map)
{
	unsigned short	x;
	unsigned short	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->matrix[y][x].x -= map->width / 2;
			map->matrix[y][x].y -= map->height / 2;
			x++;
		}
		y++;
	}
}

void	set_background(t_fdf *fdf)
{
	uint32_t	*pixel;
	uint32_t	index;

	pixel = (uint32_t *)fdf->img->pixels;
	index = fdf->img->height * fdf->img->width;
	while (index--)
		pixel[index] = 0xff000000;
}

void	close_window(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}
