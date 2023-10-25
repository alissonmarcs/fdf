/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:54:00 by almarcos          #+#    #+#             */
/*   Updated: 2023/10/25 16:30:39 by almarcos         ###   ########.fr       */
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
	{
		if (end.y > start.y)
		{
			while (walker.y != end.y)
			{
				walker.y++;
				mlx_put_pixel(data->img, walker.x, walker.y, walker.color);
			}
		}
		else
		{
			while (walker.y != end.y)
			{
				walker.y--;
				mlx_put_pixel(data->img, walker.x, walker.y, walker.color);
			}
			
		}
	}
	else if (line_data.dy == 0)
	{
		if (end.x > start.x)
		{
			while (walker.x != end.x)
			{
				walker.x++;
				mlx_put_pixel(data->img, walker.x, walker.y, walker.color);
			}
		}
		else
		{
			while (walker.x != end.x)
			{
				walker.x--;
				mlx_put_pixel(data->img, walker.x, walker.y, walker.color);
			}
		}
	}
	else
	{
		if (line_data.dx >= line_data.dy)
		{
			line_data.control = line_data.dx / 2;
			mlx_put_pixel(data->img, walker.x, walker.y, walker.color);
			while (walker.x != end.x)
			{
				walker.x += line_data.incX;
				line_data.control -= line_data.dy;
				if (line_data.control < 0)
				{
					walker.y += line_data.incY;
					line_data.control += line_data.dx;
				}
				mlx_put_pixel(data->img, walker.x, walker.y, walker.color);
			}
		}
		else
		{
			line_data.control = line_data.dy / 2;
			mlx_put_pixel(data->img, walker.x, walker.y, walker.color);
			while (walker.y != end.y)
			{
				walker.y += line_data.incY;
				line_data.control -= line_data.dx;
				if (line_data.control < 0)
				{
					walker.x += line_data.incX;
					line_data.control += line_data.dy;
				}
				mlx_put_pixel(data->img, walker.x, walker.y, walker.color);
			}
		}
	}
}
