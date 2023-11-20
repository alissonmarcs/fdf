/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:43:56 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/20 18:49:37 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_fdf	*init_fdf(char *map_name)
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
	fdf->cam = init_cam(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	return (fdf);
}

t_map	*init_map(void)
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

t_cam	*init_cam(t_fdf *fdf)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		error_handler(6);
	new_camera(fdf, cam, ISOMETRIC);
	return (cam);
}

void	init_line_data(t_line_drawing_data *line_data, t_point *start,
		t_point *end)
{
	start->x = roundf(start->x);
	start->y = roundf(start->y);
	end->x = roundf(end->x);
	end->y = roundf(end->y);
	line_data->dx = ft_abs(end->x - start->x);
	line_data->dy = ft_abs(end->y - start->y);
	line_data->control = 0;
	if (end->x > start->x)
		line_data->inc_x = 1;
	else
		line_data->inc_x = -1;
	if (end->y > start->y)
		line_data->inc_y = 1;
	else
		line_data->inc_y = -1;
}
