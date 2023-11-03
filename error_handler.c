/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:49:03 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/02 14:04:53 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void error_handler(short exit_status)
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
	exit(exit_status);
}
