/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_handler_utils_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:15:58 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/21 16:13:23 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	zoom(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_EQUAL))
		fdf->cam->scale += 0.3;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_MINUS))
		fdf->cam->scale -= 0.3;
}

void	toggle_projection(t_fdf *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		set_camera(fdf, fdf->cam, ISOMETRIC);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		set_camera(fdf, fdf->cam, TOP_VIEW);
}
