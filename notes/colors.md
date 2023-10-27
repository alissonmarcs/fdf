Representamos cores em hexadecimal.
Enxergue um número hexadecimal como sendo grupos de dois dígitos
Um grupo de dois dígitos representa um byte;
Cada byte de um número hexadecimal representa um dos canais de uma cor.

A big-endian system stores the most significant byte (left-most byte) of a word at the smallest memory address and the least significant byte (right-most byte) at the largest.
A little-endian system, in contrast, stores the least-significant byte (right-most byte) at the smallest address.

The first diagram shows a computer using little-endian. This starts the storing of the integer with the least-significant byte, 0x0D, at address a, and ends with the most-significant byte, 0x0A, at address a + 3.

o byte menos significante está nos endereços maiores.

https://www.sciencedirect.com/topics/computer-science/most-significant-byte
