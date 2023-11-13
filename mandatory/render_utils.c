/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:32:54 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/13 11:44:29 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t	put_alpha(uint32_t color)
{
	uint32_t		color_with_alpha;
	unsigned char	*ptr;

	color_with_alpha = color << 8;
	ptr = (unsigned char *)&color_with_alpha;
	*ptr = 255;
	return (color_with_alpha);
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
	int	x;
	int	y;

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
	uint32_t	i;
	uint32_t	*ptr;

	i = 0;
	ptr = (uint32_t *)fdf->img->pixels;
	while (i < fdf->img->height * fdf->img->width)
	{
		ptr[i] = 0xff000000;
		i++;
	}
}

void	hook(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}
