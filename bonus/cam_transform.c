/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:32:08 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/15 11:28:21 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_y(t_fdf *fdf, t_point *start, t_point *end, float angle)
{
	t_point	new_start;
	t_point	new_end;
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(angle);
	sin_angle = sin(angle);
	new_start.x = start->x * cos_angle + (start->z * fdf->cam->z_scale)
		* sin_angle;
	new_start.z = start->x * sin_angle + (start->z * fdf->cam->z_scale)
		* cos_angle;
	new_end.x = end->x * cos_angle + (end->z * fdf->cam->z_scale) * sin_angle;
	new_end.z = end->x * sin_angle + (end->z * fdf->cam->z_scale) * cos_angle;
	start->x = new_start.x;
	start->z = new_start.z;
	end->x = new_end.x;
	end->z = new_end.z;
}
