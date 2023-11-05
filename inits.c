/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:43:56 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/05 16:38:11 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map *init_map(void)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		error_handler(1);
	map->width = 0;
	map->height = 0;
	map->matrix = NULL;
	return (map);
}

t_fdf *init_fdf(char *map_name)
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		error_handler(4);
	fdf->map = parse_map(fdf, map_name);
	fdf->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "FDF - almarcos", 1);
	if (!fdf->mlx)
		error_handler(5);
	fdf->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!fdf->img)
		error_handler(6);
	fdf->cam = init_cam(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	return (fdf);
}

t_cam *init_cam(t_fdf *fdf)
{
	t_cam *cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		error_handler(6);
	cam->scale = get_scale(fdf);
	cam->x_offset = (WINDOW_WIDTH / 2);
	cam->y_offset = (WINDOW_HEIGHT / 2);
	cam->x_percent = ((float)fdf->map->width / (float)WINDOW_WIDTH) * 30;
	cam->y_percent = ((float)fdf->map->height / (float)WINDOW_HEIGHT) * 30;
	return (cam);
}
