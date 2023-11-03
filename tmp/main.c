#include "../fdf.h"
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

uint32_t put_alpha(uint32_t color, uint8_t alpha)
{
	return (color << 8 | alpha);
}

int main()
{
	t_fdf data;
	t_pixel start;
	t_pixel end;
	int i;

	data.mlx = mlx_init(WIDTH, HEIGHT, "lines", true);
	if (!data.mlx)
		error();
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		error();
	ft_memset(data.img->pixels, 255, data.img->width * data.img->height * sizeof (int32_t));

	mlx_image_to_window(data.mlx, data.img, 0, 0);
	

	mlx_loop_hook(data.mlx, hook, &data);

	srand(time(0)); 
	i = 0;
	while (i < 500)
	{
		start.x = randon_num(1, WIDTH - 1);
		start.y = randon_num(1, HEIGHT - 1);
		start.color = put_alpha(rand(), 255);
		end.x = randon_num(1, WIDTH - 1);
		end.y = randon_num(1, HEIGHT - 1);
		draw_line(&data, start, end);
		i++;
	}


	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);

	return (0);
}
