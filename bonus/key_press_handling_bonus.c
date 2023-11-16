/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handling_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:04:24 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/16 17:43:26 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void zoom(t_fdf *fdf, int32_t os_key);
static void movement(t_fdf *fdf, mlx_key_data_t keydata);
static void rotation(t_fdf *fdf, mlx_key_data_t keydata);

void key_press_handler(mlx_key_data_t keydata, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(fdf->mlx);
	else if ((keydata.os_key == 82 || keydata.os_key == 86) &&
			(keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		zoom(fdf, keydata.os_key);
	else if ((keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_DOWN ||
			keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_RIGHT) &&
			(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		movement(fdf, keydata);
	else if ((keydata.key == MLX_KEY_A || keydata.key  == MLX_KEY_D ||
			keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S ||
			keydata.key == MLX_KEY_Q || keydata.key ==  MLX_KEY_E) &&
			(keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		rotation(fdf, keydata);
	else if (keydata.key == MLX_KEY_R)
		reset_view(fdf);
}

static void zoom(t_fdf *fdf, int32_t os_key)
{
	if (os_key == 86)
		fdf->cam->scale += 1;
	else if (os_key == 82)
		fdf->cam->scale -= 1;
}

static void movement(t_fdf *fdf, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_UP)
		fdf->cam->y_offset -= 10;
	else if (keydata.key == MLX_KEY_DOWN)
		fdf->cam->y_offset += 10;
	else if (keydata.key == MLX_KEY_LEFT)
		fdf->cam->x_offset -= 10;
	else if (keydata.key == MLX_KEY_RIGHT)
		fdf->cam->x_offset += 10;
}

static void rotation(t_fdf *fdf, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_A)
		fdf->cam->rotation_angle_y += (5 * ONE_DEGREE_IN_RADIUS);
	else if (keydata.key == MLX_KEY_D)
		fdf->cam->rotation_angle_y -= (5 * ONE_DEGREE_IN_RADIUS);
	else if (keydata.key == MLX_KEY_W)
		fdf->cam->rotation_angle_x += (5 * ONE_DEGREE_IN_RADIUS);
	else if (keydata.key == MLX_KEY_S)
		fdf->cam->rotation_angle_x -= (5 * ONE_DEGREE_IN_RADIUS);
	else if (keydata.key == MLX_KEY_Q)
		fdf->cam->rotation_angle_z += (5 * ONE_DEGREE_IN_RADIUS);
	else if (keydata.key == MLX_KEY_E)
		fdf->cam->rotation_angle_z -= (5 * ONE_DEGREE_IN_RADIUS);
}

void reset_view(t_fdf *fdf)
{
	fdf->cam->rotation_angle_x = 0;
	fdf->cam->rotation_angle_y = 0;
	fdf->cam->rotation_angle_z = 0;
	fdf->cam->x_offset = WINDOW_WIDTH / 2;
	fdf->cam->y_offset = WINDOW_HEIGHT / 2;
}
