/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:56:08 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/21 16:13:01 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	clear_invalid_map(t_fdf *fdf, t_map *map)
{
	free(fdf);
	free(map);
	error_handler(2);
}

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

void	free_all(t_fdf *fdf)
{
	free_matrix(fdf->map);
	free(fdf->map);
	free(fdf->cam);
	free(fdf);
}
