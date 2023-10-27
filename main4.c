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

uint32_t put_alpha(uint32_t color, uint8_t alpha)
{
	return (color << 8 | alpha);
}

void black_background(void *block, int size)
{
	unsigned int *ptr;
	int i;

	ptr = block;
	i = 0;
	while (i < size)
	{
		ptr[i] = put_alpha(0, 255);
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
	//ft_bzero(data.img->pixels, data.img->width * data.img->height * 4);
	//black_background(data.img->pixels, data.img->width * data.img->height);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	
	mlx_put_pixel(data.img, 0, 0, put_alpha(rand(), 8));
	
	unsigned char *ptr;
	ptr = data.img->pixels;

	ft_printf("%d\n", *(ptr + 3));

	// for (int i = 0; i < 5; i++)
	// {
	// 	ft_printf("%d\n", ptr[i]);
	// }

	mlx_loop_hook(data.mlx, hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}