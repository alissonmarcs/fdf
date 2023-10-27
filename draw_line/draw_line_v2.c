/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_v2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:44:10 by almarcos          #+#    #+#             */
/*   Updated: 2023/10/25 17:07:58 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void draw_line(t_data *data, t_pixel start, t_pixel end)
{
	t_line_drawing_data line_data;
	t_pixel walker;

	line_data.dx = ft_abs(end.x - start.x);
	line_data.dy = ft_abs(end.y - start.y);
	if (end.x > start.x)
		line_data.incX = 1;
	else
		line_data.incX = -1;
	if (end.y > start.y)
		line_data.incY = 1;
	else
		line_data.incY = -1;
	walker.x = start.x;
	walker.y = start.y;
	walker.color = start.color;
	mlx_put_pixel(data->img, walker.x, walker.y, walker.color);
	if (line_data.dx == 0)
		draw_vertical_line(&data, start, end);
	else if (line_data.dy == 0)
		draw_horizontal_line(&data, start, end);
	else
		draw_diagonal_line(&data, start, end);
}

void draw_vertical_line(t_data *data, t_pixel start, t_pixel end)
{
	if (end.x > start.x)
	{
		
	}
}
