#include "../libft.h"
#include <fcntl.h>

int main()
{
	int fd;
	char *line;

	fd = open("./chaves-chiquinha.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
}
