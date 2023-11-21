/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:43:56 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/21 15:45:55 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*new_fdf(char *map_name)
{
	t_fdf	*fdf;

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
	fdf->cam = new_cam(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	return (fdf);
}

t_map	*new_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		error_handler(1);
	map->width = 0;
	map->height = 0;
	map->z_max = 0;
	map->matrix = NULL;
	return (map);
}

t_cam	*new_cam(t_fdf *fdf)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		error_handler(6);
	cam->scale = get_scale(fdf);
	cam->x_offset = (WINDOW_WIDTH / 2);
	cam->y_offset = (WINDOW_HEIGHT / 2);
	cam->z_scale = 1;
	if (fdf->map->z_max <= 20)
		cam->z_scale = 10;
	else if (fdf->map->z_max > 720)
		cam->z_scale = 0.03;
	return (cam);
}

void	new_line_data(t_line_drawing_data *line_data, t_point start,
		t_point end)
{
	line_data->dx = ft_abs(end.x - start.x);
	line_data->dy = ft_abs(end.y - start.y);
	if (end.x > start.x)
		line_data->inc_x = 1;
	else
		line_data->inc_x = -1;
	if (end.y > start.y)
		line_data->inc_y = 1;
	else
		line_data->inc_y = -1;
}
