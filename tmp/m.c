#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *ptr;
	unsigned int *int_ptr;

	ptr = malloc(15);
	int_ptr = (unsigned int *) ptr;

	printf("%p\n", ptr);
	printf("%p\n", int_ptr);


	*int_ptr = 0xfe000000;

	for (int i = 0; i < 8; i++)
		printf("%d\n", ptr[i]);
}
