/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:53:31 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/20 17:42:53 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void			transformations(t_fdf *fdf, t_point start, t_point end);
static void			scale(t_fdf *fdf, t_point *start, t_point *end);
static void			isometric(t_fdf *fdf, t_point *start, t_point *end);
static void			centralize(t_fdf *fdf, t_point *start, t_point *end);

void	render(void *param)
{
	t_fdf	*fdf;
	unsigned short		x;
	unsigned short		y;

	fdf = (t_fdf *)param;
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

static void	transformations(t_fdf *fdf, t_point start, t_point end)
{
	scale(fdf, &start, &end);
	if (fdf->cam->projection == ISOMETRIC)
		isometric(fdf, &start, &end);
	rotate_x(fdf, &start, &end, fdf->cam->rotation_angle_x);
	rotate_y(&start, &end, fdf->cam->rotation_angle_y);
	rotate_z(&start, &end, fdf->cam->rotation_angle_z);
	centralize(fdf, &start, &end);
	draw_line(fdf, start, end);
}

static void	scale(t_fdf *fdf, t_point *start, t_point *end)
{
	start->x *= fdf->cam->scale;
	end->x *= fdf->cam->scale;
	start->y *= fdf->cam->scale;
	end->y *= fdf->cam->scale;
}

static void	isometric(t_fdf *fdf, t_point *start, t_point *end)
{
	t_point	new_start;
	t_point	new_end;

	new_start.x = (start->x - start->y) * cos(VERTICAL_ROTATION_ANGLE);
	new_start.y = (start->x + start->y) * sin(HORIZONTAL_ROTATION_ANGLE)
		- (start->z * fdf->cam->z_scale_default);
	new_end.x = (end->x - end->y) * cos(VERTICAL_ROTATION_ANGLE);
	new_end.y = (end->x + end->y) * sin(HORIZONTAL_ROTATION_ANGLE) - (end->z
			* fdf->cam->z_scale_default);
	start->x = new_start.x;
	start->y = new_start.y;
	end->x = new_end.x;
	end->y = new_end.y;
}

static void	centralize(t_fdf *fdf, t_point *start, t_point *end)
{
	start->x += fdf->cam->x_offset;
	start->y += fdf->cam->y_offset;
	end->x += fdf->cam->x_offset;
	end->y += fdf->cam->y_offset;
}
