/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:32:54 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/05 16:58:58 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

uint32_t put_alpha(uint32_t color)
{
	uint32_t color_with_alpha;
	unsigned char *ptr;

	color_with_alpha = color << 8;
	ptr = (unsigned char *) &color_with_alpha;
	*ptr = 255;
	return (color_with_alpha);
}

float get_scale(t_fdf *fdf)
{
	// float scale;
	// float scale_x;
	// float scale_y;

	// scale_x = (float) WINDOW_WIDTH / (float) fdf->map->width;
	// scale_y = (float) WINDOW_HEIGHT / (float) fdf->map->height;
	// if (scale_x < scale_y)
	// 	scale = scale_x;
	// else
	// 	scale = scale_y;
	// if (scale < 3)
	// 	return (scale);
	// return (scale / 1.2);
	return (1);
}
