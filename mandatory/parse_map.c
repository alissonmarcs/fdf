/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:38:35 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/22 16:01:25 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	ft_free_split(split_line);
	if (!validade_lines(fd, size))
		return (0);
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

static void	process_line(t_map *map, char **spli_line, int line_index)
{
	int		column_index;
	char	*color;

	column_index = 0;
	while (column_index < map->width)
	{
		map->matrix[line_index][column_index].x = (float)column_index;
		map->matrix[line_index][column_index].y = (float)line_index;
		map->matrix[line_index][column_index].z = \
				(float)(ft_atoi(spli_line[column_index]));
		if (map->matrix[line_index][column_index].z > map->z_max)
			map->z_max = map->matrix[line_index][column_index].z;
		color = ft_strchr(spli_line[column_index], ',');
		if (color)
			map->matrix[line_index][column_index].color = \
					put_alpha(ft_hex_to_int(color + 1));
		else
		{
			if (map->matrix[line_index][column_index].z <= 0)
				map->matrix[line_index][column_index].color = 0x4ea8de;
			else
				map->matrix[line_index][column_index].color = 0xfffb6f92;
		}
		column_index++;
	}
}

static void	convert_map_to_matrix(t_map *map, char *map_name)
{
	char	*line;
	char	**split_line;
	int		line_index;
	int		fd;

	fd = open(map_name, O_RDONLY);
	line_index = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split_line = ft_split(line, ' ');
		process_line(map, split_line, line_index);
		ft_free_split(split_line);
		free(line);
		line_index++;
	}
}
