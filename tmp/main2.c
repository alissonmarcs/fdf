#include "../fdf.h"

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

uint32_t put_alpha(uint32_t color, uint8_t alpha)
{
	return (color << 8 | alpha);
}

int main()
{
	t_fdf data;
	t_pixel start;
	t_pixel end;
	uint32_t tmp;

	data.mlx = mlx_init(WIDTH, HEIGHT, "lines", true);
	if (!data.mlx)
		error();
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		error();
	ft_bzero(data.img->pixels, data.img->width * data.img->height);
	mlx_image_to_window(data.mlx, data.img, 0, 0);

	start.x = WIDTH / 2;
	start.y = HEIGHT / 2;
	start.color = 0x0000FFFFU;
	end.x = WIDTH - 1;

	end.y = 0;
	while (end.y <= (HEIGHT - 1))
	{
		draw_line(&data, start, end);
		end.y++;
	}

	end.x = 0;
	end.y = 0;
	while(end.y <= (HEIGHT - 1))
	{
		draw_line(&data, start, end);
		end.y++;
	}

	end.x = 0;
	end.y = 0;
	start.color = 0xFF0000FF;
	while (end.x != WIDTH - 1)
	{
		draw_line(&data, start, end);
		end.x++;
	}

	end.x = 0;
	end.y = HEIGHT - 1;
	while (end.x != WIDTH - 1)
	{
		draw_line(&data, start, end);
		end.x++;
	}

	mlx_loop_hook(data.mlx, hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
