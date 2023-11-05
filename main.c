/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:42:12 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/05 17:00:32 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transformations(t_fdf *fdf, t_point start, t_point end);
void	scale(t_fdf *fdf, t_point *start, t_point *end);
void	isometric(t_fdf *fdf, t_point *start, t_point *end);
void	centralize(t_fdf *fdf, t_point *start, t_point *end);

void	render(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y + 1 <= fdf->map->height)
	{
		x = 0;
		while (x + 1 <= fdf->map->width)
		{
			if (x + 1 < fdf->map->width)
				transformations(fdf, fdf->map->matrix[y][x], fdf->map->matrix[y][x + 1]);
			if (y + 1 < fdf->map->height)
				transformations(fdf, fdf->map->matrix[y][x], fdf->map->matrix[y+ 1][x]);
			x++;
		}
		y++;
	}
}

void	transformations(t_fdf *fdf, t_point start, t_point end)
{
	scale(fdf, &start, &end);
	centralize(fdf, &start, &end);
	//isometric(fdf, &start, &end);
	draw_line(fdf, start, end);
}

void	scale(t_fdf *fdf, t_point *start, t_point *end)
{
	start->x *= fdf->cam->scale;
	end->x *= fdf->cam->scale;
	start->y *= fdf->cam->scale;
	end->y *= fdf->cam->scale;
}

void isometric(t_fdf *fdf, t_point *start, t_point *end)
{
	t_point new_start;
	t_point new_end;

	new_start.x = (start->x - start->y) * cos(VERTICAL_ROTATION_ANGLE);
	new_start.y = (start->x + start->y) * sin(HORIZONTAL_ROTATION_ANGLE) - start->z;
	new_end.x = (end->x - end->y) * cos(VERTICAL_ROTATION_ANGLE);
	new_end.y = (end->x + end->y) * sin(HORIZONTAL_ROTATION_ANGLE) - end->z;
	start->x = ft_abs(new_start.x);
	start->y = ft_abs(new_start.y);
	end->x = ft_abs(new_end.x);
	end->y = ft_abs(new_end.y);
}

void centralize(t_fdf *fdf, t_point *start, t_point *end)
{
	start->x += fdf->cam->x_offset;
	start->y += fdf->cam->y_offset;
	end->x += fdf->cam->x_offset;
	end->y += fdf->cam->y_offset;

	if (start->x >= WINDOW_WIDTH)
		ft_printf("x: %d\n", start->x);
	if (start->y >= WINDOW_HEIGHT)
		ft_printf("Y: %d\n", start->y);
	if (end->x >= WINDOW_WIDTH)
		ft_printf("end x: %d\n", end->x);
	if (end->y >= WINDOW_HEIGHT)
		ft_printf("end y: %d\n", end->y);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = init_fdf(argv[1]);
	render(fdf);

	printf("%f\n", fdf->cam->x_percent);
	printf("%f\n", fdf->cam->y_percent);

	mlx_loop(fdf->mlx);
	mlx_close_window(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_matrix(fdf->map);
	free(fdf->map);
	free(fdf->cam);
	free(fdf);
}
