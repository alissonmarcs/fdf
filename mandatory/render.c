/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:53:31 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/22 16:01:37 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	set_background(fdf);
	y = 0;
	while (y + 1 <= fdf->map->height)
	{
		x = 0;
		while (x + 1 <= fdf->map->width)
		{
			if (x + 1 < fdf->map->width)
				transformations(fdf, fdf->map->matrix[y][x],
					fdf->map->matrix[y][x + 1]);
			if (y + 1 < fdf->map->height)
				transformations(fdf, fdf->map->matrix[y][x],
					fdf->map->matrix[y + 1][x]);
			x++;
		}
		y++;
	}
}

void	transformations(t_fdf *fdf, t_point start, t_point end)
{
	scale(fdf, &start, &end);
	isometric(fdf, &start, &end);
	centralize(fdf, &start, &end);
	draw_line(fdf, start, end);
}

void	scale(t_fdf *fdf, t_point *start, t_point *end)
{
	start->x *= fdf->cam->scale;
	end->x *= fdf->cam->scale;
	start->y *= fdf->cam->scale;
	end->y *= fdf->cam->scale;
}

void	isometric(t_fdf *fdf, t_point *start, t_point *end)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = (start->x - start->y) * cos(X_AXIS_ANGLE_ROTATION_RADIUS);
	new_start.y = (start->x + start->y) * sin(Z_AXIS_ANGLE_ROTATION_RADIUS)
		- (start->z * fdf->cam->z_scale);
	new_end.x = (end->x - end->y) * cos(X_AXIS_ANGLE_ROTATION_RADIUS);
	new_end.y = (end->x + end->y) * sin(Z_AXIS_ANGLE_ROTATION_RADIUS) - (end->z
			* fdf->cam->z_scale);
	start->x = new_start.x;
	start->y = new_start.y;
	end->x = new_end.x;
	end->y = new_end.y;
}

void	centralize(t_fdf *fdf, t_point *start, t_point *end)
{
	start->x += fdf->cam->x_offset;
	start->y += fdf->cam->y_offset;
	end->x += fdf->cam->x_offset;
	end->y += fdf->cam->y_offset;
}
