#include "../mandatory/fdf.h"
#include <time.h> 
#include <stdio.h>

void error()
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 1);
	exit(EXIT_FAILURE);
}

void hook(void *param)
{
	t_fdf *data;
	data = param;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

int randon_num(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

void draw_n_randomic_lines(t_fdf data, int n)
{
	t_point start;
	t_point end;

	srand(time(0));
	while (--n)
	{
		start.x = randon_num(0, WINDOW_WIDTH);
		start.y = randon_num(0, WINDOW_WIDTH);
		start.color = rand();

		end.x = randon_num(0, WINDOW_WIDTH);
		end.y = randon_num(0, WINDOW_WIDTH);
		draw_line(&data, start, end);
	}
}

void draw_infinit_hall(t_fdf data)
{
	t_point start;
	t_point end;

	start.x = WINDOW_WIDTH / 2;
	start.y = WINDOW_HEIGHT / 2;
	end.x = 0;
	end.y = 0;
	srand(time(0));
	while (end.x < WINDOW_WIDTH)
	{
		start.color = rand();
		draw_line(&data, start, end);
		end.x++;
	}
	end.y = WINDOW_HEIGHT - 1;
	end.x = 0;
	while (end.x < WINDOW_WIDTH)
	{
		start.color = rand();
		draw_line(&data, start, end);
		end.x++;
	}
}

int main()
{
	t_fdf data;
	t_point start;
	t_point end;

	data.mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "lines", true);
	if (!data.mlx)
		error();
	data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data.img)
		error();
	ft_memset(data.img->pixels, 255, data.img->width * data.img->height * sizeof (int32_t));
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_loop_hook(data.mlx, hook, &data);
	//draw_n_randomic_lines(data, 200);
	draw_infinit_hall(data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
