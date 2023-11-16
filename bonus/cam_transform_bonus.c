/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:32:08 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/16 16:55:18 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_y(t_point *start, t_point *end, float angle)
{
	t_point	new_start;
	t_point	new_end;
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	new_start.x = start->x * cos_angle + (start->z)
		* sin_angle;
	new_start.z = start->x * sin_angle + (start->z)
		* cos_angle;
	new_end.x = end->x * cos_angle + (end->z) * sin_angle;
	new_end.z = end->x * sin_angle + (end->z) * cos_angle;
	start->x = new_start.x;
	start->z = new_start.z;
	end->x = new_end.x;
	end->z = new_end.z;
}

void rotate_x(t_fdf *fdf, t_point *start, t_point *end, float angle)
{
	t_point new_start;
	t_point new_end;
	float cos_angle;
	float sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	new_start.y = start->y * cos_angle - (start->z * fdf->cam->z_scale)
		* sin_angle;
	new_start.z = start->y * sin_angle + (start->z * fdf->cam->z_scale)
		* cos_angle;
	new_end.y = end->y * cos_angle - (end->z * fdf->cam->z_scale) * sin_angle;
	new_end.z = end->y * sin_angle + (end->z * fdf->cam->z_scale) * cos_angle;
	start->y = new_start.y;
	start->z = new_start.z;
	end->y = new_end.y;
	end->z = new_end.z;
}

void rotate_z(t_point *start, t_point *end, float angle)
{
	t_point new_start;
	t_point new_end;
	float cos_angle;
	float sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	new_start.x = start->x * cos_angle - start->y * sin_angle;
	new_start.y = start->x * sin_angle + start->y * cos_angle;
	new_end.x = end->x * cos_angle - end->y * sin_angle;
	new_end.y = end->x * sin_angle + end->y * cos_angle;
	start->x = new_start.x;
	start->y = new_start.y;
	end->x = new_end.x;
	end->y = new_end.y;
}
