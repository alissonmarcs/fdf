/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:42:12 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/03 16:07:44 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	transformations(t_fdf *fdf, t_point start, t_point end);
void	scale(t_point *start, t_point *end);

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
	scale(&start, &end);
	draw_line(fdf, start, end);
}

void	scale(t_point *start, t_point *end)
{
	int	scale;

	scale = get_scale_factor();
	start->x *= scale;
	start->y *= scale;
	end->x *= scale;
	end->y *= scale;
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	// mlx_set_setting(MLX_HEADLESS, 1);
	fdf = init_fdf(argv[1]);
	render(fdf);
	mlx_loop(fdf->mlx);
	mlx_close_window(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_matrix(fdf->map);
	free(fdf->map);
	free(fdf);
}
