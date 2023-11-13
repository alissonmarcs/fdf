/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_errors_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:49:03 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/13 09:43:57 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	validate_map_name(char *map_name)
{
	int	fd;

	if (!ft_strnstr(map_name, ".fdf", ft_strlen(map_name)))
		error_handler(8);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		error_handler(9);
	close(fd);
}

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
	exit(exit_status);
}
