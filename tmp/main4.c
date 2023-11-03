#include "../fdf.h"
#include <time.h>

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

uint32_t put_alpha(uint32_t color)
{
	uint32_t color_with_alpha;
	unsigned char *ptr;

	color_with_alpha = color << 8;
	ptr = (unsigned char *) &color_with_alpha;
	*ptr = 255;
	return (color_with_alpha);
}

// void set_background(void *block, int size)
// {
// 	uint32_t *ptr;
// 	int i;

// 	i = 0;
// 	ptr = block;
// 	while (i < size)
// 	{
// 		ptr[i] = put_alpha(0x000000, 255);
// 		i++;
// 	}
// }

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int main()
{
	t_fdf data;

	//mlx_set_setting(MLX_HEADLESS, 1);
	data.mlx = mlx_init(WIDTH, HEIGHT, "lines", true);
	if (!data.mlx)
		error();
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		error();
	//set_background(data.img->pixels, data.img->width * data.img->height);
	mlx_image_to_window(data.mlx, data.img, 0, 0);

	// int color;
	// unsigned char *pointer;

	// pointer = (unsigned char *) &color;

	// *pointer = 255;
	// *(pointer + 1) = 0;
	// *(pointer + 2) = 0;
	// *(pointer + 3) = 0;

	t_point start = {0, 0, 0, put_alpha(0xff0000)};
	t_point end = {50, 50, 0, 0xffffffff};
	draw_line(&data, start, end);

	// unsigned char *ptr;
	// ptr = data.img->pixels;
	// for (int i = 0; i < 10; i++)
	// 	ft_printf("%d\n", *(ptr+i));

	mlx_loop_hook(data.mlx, hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
}
