/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:16:39 by almarcos          #+#    #+#             */
/*   Updated: 2023/10/27 14:57:33 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_map map;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <path/to/map.fdf>\n", 1);
		exit(EXIT_SUCCESS);
	}
	map.size = 0;
	parse_map(&map, argv[1]);
}
