## still reachable na MLX42
Resumindo: a memória indicada como "still reachable" é devolvida ao sistema operacional.

Alguns links sobre isso:

Explicação geral:

https://itecnote.com/tecnote/r-still-reachable-leak-detected-by-valgrind/
https://student.cs.uwaterloo.ca/~cs241/valgrind.pdf

Isso ocorre em outras libs também, como na GNU C++ Library:
https://gcc.gnu.org/onlinedocs/libstdc++/faq.html#faq.memory_leaks

A própria documentação do valgrind diz que isso não é problemático:

- "still reachable" means your program is probably ok -- it didn't free some memory it could have. This is quite common and often reasonable.

https://valgrind.org/docs/manual/faq.html#faq.deflost
