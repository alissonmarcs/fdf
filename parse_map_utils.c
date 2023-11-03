/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:34:04 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/03 10:33:09 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	validade_lines(int fd, int size)
{
	int		check;
	char	*line;
	char	**split_line;
	int		current_line_size;

	check = true;
	current_line_size = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split_line = ft_split(line, ' ');
		while (split_line[current_line_size]
			&& split_line[current_line_size][0] != '\n')
			current_line_size++;
		if (current_line_size != size)
			check = false;
		current_line_size = 0;
		free(line);
		free_split(split_line);
	}
	close(fd);
	return (check);
}

void clear_map(t_fdf *fdf, t_map *map)
{
	free(fdf);
	free(map);
	error_handler(2);
}

t_point **alloc_matrix(int width, int height)
{
	t_point **matrix;

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

void free_matrix(t_map *map)
{
	while (map->height--)
		free(map->matrix[map->height]);
	free(map->matrix);
}

void free_split(char **split_line)
{
	int index;

	index = 0;
	while (split_line[index] != NULL)
	{
		free(split_line[index]);
		index++;
	}
	free(split_line);
}
