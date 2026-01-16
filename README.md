# Get Next Line

*This project has been created as part of the 42 curriculum by mkhoubaz*

## Description

**Get Next Line** is a **C** project that consists of implementing a `Get_next_line` function.
The goal of this function is to read from file descriptor and return **one line at atime**, ending with new line character (`\n`) if present, or `NULL` when nothing left to read ot an error occurs.

The project focuses on:

- Using the `read()` system call
- Managing memory safely (no leaks)
- Handle static variables
- Supporting different `BUFFER_SIZE` value
- Managing multiple file descriptor in Bonus part

## Instructions

### How to run project

Use **CC** compiler with the required flags:

```sh
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c && ./a.out
```

Note:
> Flags to any warning be come error

Using custom**BUFFER_SIZE** marco

```sh
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=1337 && ./a.out
```

To verify memory leaks use **Valgrind**

```sh
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42 && valgrind -s --track-origins=yes  --leak-check=full ./a.out
```

Note:
> -s for summary error report --track-origins=yes to track uninitialized values --leak-check=full provides detailed information

### Usage examples

File main example to test Mandatory part

```c
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("text.txt", O_RDONLY);

    char *line;

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    close(fd);
}
```

File main example to test Bonus part (Multiple file descriptor)

```c
#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("text.txt", O_RDONLY);
    int fd2 = open("text2.txt", O_RDONLY);
    int fd3 = open("text3.txt", O_RDONLY);

    char *line;

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    line = get_next_line(fd2);
    printf("%s", line);
    free(line);

    line = get_next_line(fd2);
    printf("%s", line);
    free(line);

    line = get_next_line(fd3);
    printf("%s", line);
    free(line);

    line = get_next_line(fd2);
    printf("%s", line);
    free(line);

    line = get_next_line(fd3);
    printf("%s", line);
    free(line);

    line = get_next_line(fd);
    printf("%s", line);
    free(line);

    close(fd);
}
```

## Resources

### Website and books

Static variables in C [geeksforgeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/)

`read()` system call documentation [opengroup](https://pubs.opengroup.org/onlinepubs/009604599/functions/read.html)

File descriptor [linux programming interface book](https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf)

File offset and read behavior [IC221 - Systems Programming](https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L09/Class.html) and [linux programming interface book](https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf)

### How I use AI

AI tool were used only to generated test file and simple input data.

## Algorithm Explanation and justification

1. A static variable (`line`) use to store leftover data between calls.
2. Memory is allocate for a buffer (`buf`) of size `BUFFER_SIZE` + 1 to store data read by `read()`.
3. The function read from file descriptor until:
    1. A newline (`\n`) is found, or
    2. `read()` return `0` (end of file), or
    3. An error occurs.
4. Each buffer read is appended to static variable using a custom `ft_strjoin()`.
5. When a newline detected:
    1. A substring from the beginning up to the newline using `ft_substr()` and returned.
    2. The remaining data after the newline is kept in the static variable (`line`) for the next call
6. If the end of file is reached and no newline:
    1. The remaining content is returned.
    2. The static variable is freed using `free()`.
7. All allocated memory is carefully freed to avoid leaks.

### Feature

- Return one line at time from file descriptor
- Handle macro `BUFFER_SIZE`
- No memory leaks
- Bound: support multiple file descriptor
- Handle when `malloc()` and `read()` filed
