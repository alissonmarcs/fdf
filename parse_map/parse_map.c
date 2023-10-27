/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:41:31 by alisson           #+#    #+#             */
/*   Updated: 2023/10/27 15:34:28 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point *read_map(int fd, t_map *map);

void parse_map(t_map *map, char *map_file)
{
	int fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error on open map.\n", 1);
		exit(EXIT_FAILURE);
	}
	map->points = read_map(fd, map);
	return ;
}

t_point *read_map(int fd, t_map *map)
{
	char *line;
	char *copy;
	t_point *point;

	line = get_next_line(fd);
	copy = line;
	while (*line)
	{
		while (ft_isdigit(line))
		{
			
		}
	}
	
}
