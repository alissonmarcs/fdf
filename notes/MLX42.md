Imagens e instâncias
Imagens são para desenhar, instâncias são copias de imagens.

typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels; // é um simples ponteiro que vai conter o endereço para um bloco de memória que vai guardar as informações de pixels.
	mlx_instance_t*	instances; // as instâncias de images que vão ter as cordedanas.
	int32_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;
