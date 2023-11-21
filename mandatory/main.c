/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:42:12 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/21 16:17:19 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		error_handler(7);
	validate_map_name(argv[1]);
	fdf = new_fdf(argv[1]);
	mlx_loop_hook(fdf->mlx, close_window, fdf);
	render(fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_all(fdf);
}
