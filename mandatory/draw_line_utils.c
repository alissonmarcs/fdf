/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alisson <alisson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:09:45 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/20 11:05:01 by alisson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, uint32_t x, uint32_t y, uint32_t color)
{
	if ((x < WINDOW_WIDTH) && (y < WINDOW_HEIGHT))
		mlx_put_pixel(fdf->img, x, y, color);
}
