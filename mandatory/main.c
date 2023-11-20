/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:42:12 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/20 11:10:12 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		error_handler(7);
	validate_map_name(argv[1]);
	fdf = init_fdf(argv[1]);
	mlx_loop_hook(fdf->mlx, close_window, fdf);
	render(fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_matrix(fdf->map);
	free(fdf->map);
	free(fdf->cam);
	free(fdf);
}
