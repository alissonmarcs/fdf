## Sobre o cmake
Gerador de Makefiles
cmake é um "buildsystem generator". Um buildsystem descreve como compilar um projeto. Makefiles são buildsystems. Em outras palavras, o cmake gera Makefiles de forma automatizada.

Para gerar um buildsystem:

`cmake -B build`

-B build especifica o diretório onde o Makefile será criado. Nesse caso, na pasta build.

Uma vez gerado o buildsystem, você vai querer compilar de fato o software. Para isso:

`cmake --build build -j4`

--build build especifica onde será guardado o binário final da compilação. Nesse caso, na pasta build.

-j4 especifica quantos jobs paralelos serão usados.
