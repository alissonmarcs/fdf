#include "fdf.h"
#include <time.h>

void error()
{
	ft_putstr_fd((char *)mlx_strerror(mlx_errno), 1);
	exit(EXIT_FAILURE);
}

void hook(void *param)
{
	t_data *data;
	data = param;

	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
}

int randon_num(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

uint32_t put_alpha(uint32_t color, uint32_t alpha)
{
	
	return (((color & 0x00FFFFFF | alpha << 24) | (color & 0xFF0000)));
}

void set_background(void *block, int size)
{
	uint32_t *ptr;
	int i;

	i = 0;
	ptr = block;
	while (i < size)
	{
		ptr[i] = put_alpha(0x000000, 255);
		i++;
	}
}

int main()
{
	t_data data;
	t_pixel start;
	t_pixel end;

	//mlx_set_setting(MLX_HEADLESS, 1);
	data.mlx = mlx_init(WIDTH, HEIGHT, "lines", true);
	if (!data.mlx)
		error();
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		error();
	set_background(data.img->pixels, data.img->width * data.img->height);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	
	unsigned char *ptr;
	ptr = data.img->pixels;
	for (int i = 0; i < 10; i++)
	{
		ft_printf("%d\n", ptr[i]);
	}

	mlx_loop_hook(data.mlx, hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
