/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:15:58 by alisson           #+#    #+#             */
/*   Updated: 2023/11/20 19:10:12 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
		fdf->cam->scale += 0.3;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		fdf->cam->scale -= 0.3;
}

void projection(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		new_camera(fdf, fdf->cam, ISOMETRIC);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		new_camera(fdf, fdf->cam, TOP_VIEW);
}

void new_camera(t_fdf *fdf, t_cam *cam, short PROJECTION)
{
	cam->projection = PROJECTION;
	cam->scale = get_scale(fdf);
	cam->x_offset = (WINDOW_WIDTH / 2);
	cam->y_offset = (WINDOW_HEIGHT / 2);
	cam->rotation_angle_x = 0;
	cam->rotation_angle_y = 0;
	cam->rotation_angle_z = 0;
	if (fdf->map->width <= 500)
		cam->z_scale_factor = 2;
	else
		cam->z_scale_factor = 0.009;
	if (fdf->map->z_max <= 20)
		cam->z_scale_default = 10;
	else if (fdf->map->z_max > 850)
		cam->z_scale_default = 0.03;
	else
		cam->z_scale_default = 1;
}