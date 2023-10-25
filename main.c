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

int main()
{
	t_data data;
	t_pixel start;
	t_pixel end;
	int i;

	//mlx_set_setting(MLX_HEADLESS, 1);
	data.mlx = mlx_init(WIDTH, HEIGHT, "lines", true);
	if (!data.mlx)
		error();
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		error();
	ft_memset(data.img->pixels, 255, data.img->width * data.img->height * sizeof (int32_t));

	mlx_image_to_window(data.mlx, data.img, 0, 0);
	

	mlx_loop_hook(data.mlx, hook, &data);

	// start.x = 1;
	// start.y = 1;
	// start.color = 700;
	// end.x = 6;
	// end.y = 2;

	// draw_line(&data, start, end);
	srand(time(0)); 
	i = 0;
	while (i < 900)
	{
		start.x = (rand() % ((WIDTH - 1)- 1 + 1)) + 1;
		start.y = (rand() % ((HEIGHT - 1) - 1 + 1)) + 1;
		end.x = (rand() % ((WIDTH - 1)- 1 + 1)) + 1;
		end.y = (rand() % ((HEIGHT - 1) - 1 + 1)) + 1;
		draw_line(&data, start, end);
		i++;
	}

	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);

	return (0);
}
