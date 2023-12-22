/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:20:34 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/21 15:50:50 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**alloc_matrix(int width, int height)
{
	t_point	**matrix;

	matrix = malloc(height * sizeof(t_point *));
	if (!matrix)
		error_handler(3);
	while (height--)
	{
		matrix[height] = ft_calloc(width, sizeof(t_point));
		if (!matrix[height])
			error_handler(3);
	}
	return (matrix);
}

void	free_matrix(t_map *map)
{
	while (map->height--)
		free(map->matrix[map->height]);
	free(map->matrix);
}

void	close_window(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}

void	free_all(t_fdf *fdf)
{
	free_matrix(fdf->map);
	free(fdf->map);
	free(fdf->cam);
	free(fdf);
}
