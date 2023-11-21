/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:06:15 by almarcos          #+#    #+#             */
/*   Updated: 2023/11/21 16:06:35 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	draw_vertical_line(t_fdf *fdf, t_point start, t_point end);
static void	draw_horizontal_line(t_fdf *fdf, t_point start, t_point end);
static void	draw_line_larger_y_axis(t_fdf *fdf, t_line_drawing_data line_data,
				t_point start, t_point end);
static void	draw_line_larger_x_axis(t_fdf *fdf, t_line_drawing_data line_data,
				t_point start, t_point end);

void	draw_line(t_fdf *fdf, t_point start, t_point end)
{
	t_line_drawing_data	line_data;

	new_line_data(&line_data, &start, &end);
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

static void	draw_vertical_line(t_fdf *fdf, t_point start, t_point end)
{
	if ((int) start.y < (int) end.y)
	{
		while ((int)start.y < (int)end.y)
		{
			start.y++;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
	else
	{
		while ((int)start.y > (int)end.y)
		{
			start.y--;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
}

static void	draw_horizontal_line(t_fdf *fdf, t_point start, t_point end)
{
	if ((int) start.x < (int) end.x)
	{
		while ((int)start.x < (int)end.x)
		{
			start.x++;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
	else
	{
		while ((int)start.x > (int)end.x)
		{
			start.x--;
			put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		}
	}
}

static void	draw_line_larger_x_axis(t_fdf *fdf, t_line_drawing_data line_data,
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

static void	draw_line_larger_y_axis(t_fdf *fdf, t_line_drawing_data line_data,
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
