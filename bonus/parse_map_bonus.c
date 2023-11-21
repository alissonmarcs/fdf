/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:38:35 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/21 16:04:26 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	get_map_width(char *map);
static int	get_map_height(char *map_name);
static void	process_line(t_map *map, char **spli_line, int line_number);
static void	convert_map_to_matrix(t_map *map, char *map_name);

t_map	*parse_map(t_fdf *fdf, char *map_name)
{
	t_map	*map;

	map = new_map();
	map->width = get_map_width(map_name);
	map->height = get_map_height(map_name);
	if (map->width < 2 || map->height < 2)
		clear_invalid_map(fdf, map);
	map->matrix = alloc_matrix(map->width, map->height);
	convert_map_to_matrix(map, map_name);
	center_to_origin(map);
	return (map);
}

static int	get_map_width(char *map_name)
{
	int		size;
	int		fd;
	char	*line;
	char	**split_line;

	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	size = 0;
	while (split_line[size] && split_line[size][0] != '\n')
		size++;
	free(line);
	free_split(split_line);
	if (!validade_lines(fd, size))
		return (false);
	return (size);
}

static int	get_map_height(char *map_name)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(map_name, O_RDONLY);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static void	process_line(t_map *map, char **spli_line, int line_number)
{
	int		column_number;
	char	*color;

	column_number = 0;
	while (column_number < map->width)
	{
		map->matrix[line_number][column_number].x = (float)column_number;
		map->matrix[line_number][column_number].y = (float)line_number;
		map->matrix[line_number][column_number].z = \
				(float)(ft_atoi(spli_line[column_number]));
		if (map->matrix[line_number][column_number].z > map->z_max)
			map->z_max = map->matrix[line_number][column_number].z;
		color = ft_strchr(spli_line[column_number], ',');
		if (color)
			map->matrix[line_number][column_number].color = \
					put_alpha(ft_hex_to_int(color + 1));
		else
		{
			if (map->matrix[line_number][column_number].z <= 0)
				map->matrix[line_number][column_number].color = 0x4ea8de;
			else
				map->matrix[line_number][column_number].color = 0xfffb6f92;
		}
		column_number++;
	}
}

static void	convert_map_to_matrix(t_map *map, char *map_name)
{
	char	*line;
	char	**split_line;
	int		line_number;
	int		fd;

	fd = open(map_name, O_RDONLY);
	line_number = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split_line = ft_split(line, ' ');
		process_line(map, split_line, line_number);
		free_split(split_line);
		free(line);
		line_number++;
	}
}
