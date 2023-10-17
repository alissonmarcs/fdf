# Libft
First project of 42 School, it is about create our own C library with some functions from Standard C Library and additional others. I learned string and memory manipulation, linked lists, pointers, structs, typedefs and a lot more. Each function implementation is in its own .c file.

## Functions
| Funcion | Description |
|---------|-------------|
|[`ft_atoi`](https://github.com/alissonmarcs/Libft/blob/main/ft_atoi.c)| Convert a string to int. |
|[`ft_itoa`](https://github.com/alissonmarcs/Libft/blob/main/ft_itoa.c)| Convert int to a new string. |
|[`ft_calloc`](https://github.com/alissonmarcs/Libft/blob/main/ft_calloc.c)|Alloc a array of `nmemb` elements with `size` bytes each. |
|[`ft_isalnum`](https://github.com/alissonmarcs/Libft/blob/main/ft_isalnum.c)| Return if `c` is alfabetical or numeric. |
|[`ft_isalpha`](https://github.com/alissonmarcs/Libft/blob/main/ft_isalpha.c)| Return if `c` is alfabetical. |
|[`ft_isascii`](https://github.com/alissonmarcs/Libft/blob/main/ft_isascii.c)| Return if `c` is ascii. |
|[`ft_isdigit`](https://github.com/alissonmarcs/Libft/blob/main/ft_isdigit.c)| Return if `c` is digit.|
|[`ft_isprint`](https://github.com/alissonmarcs/Libft/blob/main/ft_isprint.c)| Return if `c` is printable.|
|[`ft_tolower`](https://github.com/alissonmarcs/Libft/blob/main/ft_tolower.c)| Convert a char to lower case. |
|[`ft_toupper`](https://github.com/alissonmarcs/Libft/blob/main/ft_toupper.c)| Convert a char to upper case. |
|[`ft_memset`](https://github.com/alissonmarcs/Libft/blob/main/ft_memset.c)| Set byte `c` in first `n` bytes of a block memory.|
|[`ft_bzero`](https://github.com/alissonmarcs/Libft/blob/main/ft_bzero.c)| Set `0` in first `n` bytes of a memory block. |
|[`ft_memchr`](https://github.com/alissonmarcs/Libft/blob/main/ft_memchr.c)|Scans for `c` in first `n` bytes of a memory block, and return a pointer to it.|
|[`ft_memcpy`](https://github.com/alissonmarcs/Libft/blob/main/ft_memcpy.c)|Copy first `n` bytes of `src` to `dest`. If overlap occours, the result is undefined.|
|[`ft_memmove`](https://github.com/alissonmarcs/Libft/blob/main/ft_memmove.c)| Copy first `n` bytes of `src` to `dest`. Treat ovarlap if it occours.|
|[`ft_memcmp`](https://github.com/alissonmarcs/Libft/blob/main/ft_memcmp.c)|Compare first `n` bytes of two block memory.|
|[`ft_putchar_fd`](https://github.com/alissonmarcs/Libft/blob/main/ft_putchar_fd.c)|Put char `c` in `fd`.|
|[`ft_putstr_fd`](https://github.com/alissonmarcs/Libft/blob/main/ft_putstr_fd.c)| Put string in `fd`. |
|[`ft_putendl_fd`](https://github.com/alissonmarcs/Libft/blob/main/ft_putendl_fd.c)| Put string in `fd` with new line character.|
|[`ft_putnbr_fd`](https://github.com/alissonmarcs/Libft/blob/main/ft_putnbr_fd.c)| Put number in `fd`. |
|[`ft_strlen`](https://github.com/alissonmarcs/Libft/blob/main/ft_strlen.c)| Return length of string `*s`. |
|[`ft_strchr`](https://github.com/alissonmarcs/Libft/blob/main/ft_strchr.c)| Return a pointer to first occurrence of `c` in string. |
|[`ft_strrchr`](https://github.com/alissonmarcs/Libft/blob/main/ft_strrchr.c)| Return last occurrence of char `c` in string `*s`. |
|[`ft_strdup`](https://github.com/alissonmarcs/Libft/blob/main/ft_strdup.c)| Duplicate a string. |
|[`ft_strlcpy`](https://github.com/alissonmarcs/Libft/blob/main/ft_strlcpy.c)| Copy string `*src` to `*dst`. |
|[`ft_strlcat`](https://github.com/alissonmarcs/Libft/blob/main/ft_strlcat.c)| Concatenate two strings `*dst` and `*src`. |
|[`ft_strjoin`](https://github.com/alissonmarcs/Libft/blob/main/ft_strjoin.c)| Return a new string resulting of concatenation of `*s1` and `*s2`. |
|[`ft_strncmp`](https://github.com/alissonmarcs/Libft/blob/main/ft_strncmp.c)| Compare first `n` bytes of two strings `*s1` and `*s2`. |
|[`ft_strnstr`](https://github.com/alissonmarcs/Libft/blob/main/ft_strnstr.c)| Return a substring of a string. |
|[`ft_substr`](https://github.com/alissonmarcs/Libft/blob/main/ft_substr.c)| Return new substring of string `*s`. |
|[`ft_strtrim`](https://github.com/alissonmarcs/Libft/blob/main/ft_strtrim.c)| Return new string `*s1` with it ends trimmed. |
|[`ft_split`](https://github.com/alissonmarcs/Libft/blob/main/ft_split.c)| Split string in array of words. |
|[`ft_striteri`](https://github.com/alissonmarcs/Libft/blob/main/ft_striteri.c)| Call a function `f` to every character in string `*s`.|
|[`ft_strmapi`](https://github.com/alissonmarcs/Libft/blob/main/ft_strmapi.c)| Map every char of string `*s` to a new string. |

## Bonus functions
|Function| Description |
|----------|-----------|
|[`ft_lstnew`](https://github.com/alissonmarcs/Libft/blob/main/ft_lstnew_bonus.c)| Create a new node. |
|[`ft_lstadd_front`](https://github.com/alissonmarcs/Libft/blob/main/ft_lstadd_front_bonus.c)| Add a node at head of a list. |
|[`ft_lstadd_back`](https://github.com/alissonmarcs/Libft/blob/main/ft_lstadd_back_bonus.c)| Add a node at tail of a list. |
|[`ft_lstsize`](https://github.com/alissonmarcs/Libft/blob/main/ft_lstsize_bonus.c)| Return size of a list. |
|[`ft_lstlast`](https://github.com/alissonmarcs/Libft/blob/main/ft_lstlast_bonus.c)| Return last node of a list. |
|[`ft_lstdelone`](https://github.com/alissonmarcs/Libft/blob/main/ft_lstdelone_bonus.c)| Delete one node. |
|[`ft_lstclear`](https://github.com/alissonmarcs/Libft/blob/main/ft_lstclear_bonus.c)| Delete a node and their sucessors.|
|[`ft_lstiter`](https://github.com/alissonmarcs/Libft/blob/main/ft_lstiter_bonus.c)| Call function `f` to every node in list.|
|[`ft_lstmap`](https://github.com/alissonmarcs/Libft/blob/main/ft_lstmap_bonus.c)| Map every node of a list in a new list.|

## How to use

Clone this repository:
```shell
$ git clone https://github.com/alissonmarcs/Libft.git
```

Run `make` on it:
```shell
$ cd Libft
$ make
```

If you want to use linked lists, run `make bonus`:
```shell
$ make bonus
```

Include `libft.h` in your `.c`:
```c
#include "libft.h"
```

Compile your `.c` with the library:
```shell
$ cc my_program.c libft.a
```
