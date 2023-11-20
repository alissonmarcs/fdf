/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handling_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:04:24 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/20 18:55:03 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void movement(t_fdf *fdf);
static void rotation(t_fdf *fdf);
static void reset_view(t_fdf *fdf);
static void z_scale(t_fdf *fdf);

void key_press_handler(void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *) param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	reset_view(fdf);
	movement(fdf);
	z_scale(fdf);
	rotation(fdf);
	zoom(fdf);
	projection(fdf);
}

static void z_scale(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_K))
		fdf->cam->z_scale_default += fdf->cam->z_scale_factor;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_J))
		fdf->cam->z_scale_default -= fdf->cam->z_scale_factor;
}

static void movement(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->cam->y_offset -= 25;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->cam->y_offset += 25;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->cam->x_offset -= 25;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->cam->x_offset += 25;
}

static void rotation(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
		fdf->cam->rotation_angle_y += (15 * ONE_DEGREE_IN_RADIUS);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
		fdf->cam->rotation_angle_y -= (15 * ONE_DEGREE_IN_RADIUS);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
		fdf->cam->rotation_angle_x += (15 * ONE_DEGREE_IN_RADIUS);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->cam->rotation_angle_x -= (15 * ONE_DEGREE_IN_RADIUS);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Q))
		fdf->cam->rotation_angle_z += (15 * ONE_DEGREE_IN_RADIUS);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_E))
		fdf->cam->rotation_angle_z -= (15 * ONE_DEGREE_IN_RADIUS);
}

static void reset_view(t_fdf *fdf)
{
	if (!mlx_is_key_down(fdf->mlx, MLX_KEY_R))
		return ;
	new_camera(fdf, fdf->cam, fdf->cam->projection);
}
