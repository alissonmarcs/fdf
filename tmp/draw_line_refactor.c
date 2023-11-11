/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_refactor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:54:00 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/10 15:01:14 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/fdf.h"

void	draw_vertical_line(t_fdf *fdf, t_point start, t_point end);
void	draw_horizontal_line(t_fdf *fdf, t_point start, t_point end);
void	draw_line_larger_y_axis(t_fdf *fdf, t_line_drawing_data line_data,
			t_point start, t_point end);
void	draw_line_larger_x_axis(t_fdf *fdf, t_line_drawing_data line_data,
			t_point start, t_point end);

void	put_pixel(t_fdf *fdf, uint32_t x, uint32_t y, uint32_t color)
{
	if ((x >= 0 && x < WINDOW_WIDTH) && (y >= 0 && y < WINDOW_HEIGHT))
		mlx_put_pixel(fdf->img, x, y, color);
}

void	draw_vertical_line(t_fdf *fdf, t_point start, t_point end)
{
	if (end.y > start.y)
	{
		while ((int)start.y != (int)end.y)
		{
			start.y++;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
	else
	{
		while ((int)start.y != (int)end.y)
		{
			start.y--;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
}

void	draw_horizontal_line(t_fdf *fdf, t_point start, t_point end)
{
	if (end.x > start.x)
	{
		while ((int)start.x != (int)end.x)
		{
			start.x++;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
	else
	{
		while ((int)start.x != (int)end.x)
		{
			start.x--;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
}

void	init_line_data(t_line_drawing_data *line_data, t_point start,
		t_point end)
{
	line_data->dx = ft_abs(end.x - start.x);
	line_data->dy = ft_abs(end.y - start.y);
	if (end.x > start.x)
		line_data->inc_x = 1;
	else
		line_data->inc_x = -1;
	if (end.y > start.y)
		line_data->inc_y = 1;
	else
		line_data->inc_y = -1;
}

void	draw_line(t_fdf *fdf, t_point start, t_point end)
{
	t_line_drawing_data	line_data;

	init_line_data(&line_data, start, end);
	if (line_data.dx == 0)
		draw_vertical_line(fdf, start, end);
	else if (line_data.dy == 0)
		draw_horizontal_line(fdf, start, end);
	else
	{
		if (line_data.dx >= line_data.dy)
			draw_line_larger_x_axis(fdf, line_data, start, end);
		else
			draw_line_larger_y_axis(fdf, line_data, start, end);
	}
}

void	draw_line_larger_x_axis(t_fdf *fdf, t_line_drawing_data line_data,
		t_point start, t_point end)
{
	line_data.control = line_data.dx / 2;
	put_pixel(fdf, (int)start.x, (int)start.y, (int)start.color);
	while ((int)start.x != (int)end.x)
	{
		start.x += line_data.inc_x;
		line_data.control -= line_data.dy;
		if (line_data.control < 0)
		{
			start.y += line_data.inc_y;
			line_data.control += line_data.dx;
		}
		put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}

void	draw_line_larger_y_axis(t_fdf *fdf, t_line_drawing_data line_data,
		t_point start, t_point end)
{
	line_data.control = line_data.dy / 2;
	put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	while ((int)start.y != (int)end.y)
	{
		start.y += line_data.inc_y;
		line_data.control -= line_data.dx;
		if (line_data.control < 0)
		{
			start.x += line_data.inc_x;
			line_data.control += line_data.dy;
		}
		put_pixel(fdf, (int)start.x, (int)start.y, start.color);
	}
}
