/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:49:03 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/23 10:46:43 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_handler(short exit_status)
{
	if (exit_status == 1)
		ft_putstr_fd("Allocation of memory for map failed.\n", 1);
	else if (exit_status == 2)
		ft_putstr_fd("Wrong map file.\n", 1);
	else if (exit_status == 3)
		ft_putstr_fd("Allocation of memory for matrix failed.\n", 1);
	else if (exit_status == 4)
		ft_putstr_fd("Allocation of memory for fdf struct failed.\n", 1);
	else if (exit_status == 4)
		ft_putstr_fd("Initialization for MLX42 failed.\n", 1);
	else if (exit_status == 5)
		ft_putstr_fd("Creation of image for MLX42 failed.\n", 1);
	else if (exit_status == 6)
		ft_putstr_fd("Allocation of memory for cam struct failed\n.", 1);
	else if (exit_status == 7)
		ft_putstr_fd("Usage: <filename>\n", 1);
	else if (exit_status == 8)
		ft_putstr_fd("Invalid extension in map name\n", 1);
	else if (exit_status == 9)
		ft_putstr_fd("Map does not exist\n", 1);
	else if (exit_status == 10)
		ft_putstr_fd("Empty map\n", 1);
	exit(exit_status);
}

void	validate_map_file(char *map)
{
	int		fd;
	char	*content;

	if (ft_strnstr(map, ".fdf", ft_strlen(map)) == NULL)
		error_handler(8);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_handler(9);
	content = get_next_line(fd);
	if (content == NULL)
		error_handler(10);
	free(content);
	get_next_line(-1);
	close(fd);
}
