/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:34:04 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/21 13:58:06 by almarcos         ###   ########.fr       */
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

uint32_t	put_alpha(uint32_t color)
{
	uint32_t		new_color;
	unsigned char	*ptr;

	new_color = color << 8;
	ptr = (unsigned char *)&new_color;
	*ptr = 255;
	return (new_color);
}

void	clear_invalid_map(t_fdf *fdf, t_map *map)
{
	free(fdf);
	free(map);
	error_handler(2);
}

float	get_scale(t_fdf *fdf)
{
	float	scale;
	float	scale_x;
	float	scale_y;

	scale_x = WINDOW_WIDTH / (float)fdf->map->width;
	scale_y = WINDOW_HEIGHT / (float)fdf->map->height;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale / 1.55);
}

void	center_to_origin(t_map *map)
{
	unsigned short	x;
	unsigned short	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->matrix[y][x].x -= map->width / 2;
			map->matrix[y][x].y -= map->height / 2;
			x++;
		}
		y++;
	}
}
