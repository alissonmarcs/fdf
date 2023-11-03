Representamos cores em hexadecimal.
Enxergue um número hexadecimal como sendo grupos de dois dígitos
Um grupo de dois dígitos representa um byte;
Cada byte de um número hexadecimal representa um dos canais de uma cor.

A big-endian system stores the most significant byte (left-most byte) of a word at the smallest memory address and the least significant byte (right-most byte) at the largest.
A little-endian system, in contrast, stores the least-significant byte (right-most byte) at the smallest address.

The first diagram shows a computer using little-endian. This starts the storing of the integer with the least-significant byte, 0x0D, at address a, and ends with the most-significant byte, 0x0A, at address a + 3.

o byte menos significante está nos endereços maiores.

https://www.sciencedirect.com/topics/computer-science/most-significant-byte

quando um ponteiro char aponta para um int, ele está apontando pro byte menos significante desse int.

char *ptr;
int color;

ptr = (char *) &color;

é exatamente esse byte que representa o alpha.

Os imacs da escola são Big endian, ou seja, o byte mais significativo está alocado nos endereços menores. Por isso, quando você printa os bytes do buffer de memória de imagem da MLX42, o primeiro byte representa a cor vermelha, o segundo a cor verde, e assim vai.

Mainzinha para te mostrar que um ponteiro char apontando para um int, está apontando pro byte menos significativo desse int.
