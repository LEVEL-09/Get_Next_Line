# Get Next Line

This project has been created as part of the 42 curriculum by **_mkhoubaz_**

## Description

This project in **C** about created **Get_next_line** function read from file descriptor use function **read()** and return one line or return NULL if any error happened or nothing else to read use **static variable** without leaks.

## Instructions

### How to run project

Use **CC** compiler and it flags `-Wall -Wextra -Werror`

```txt
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c && ./a.out
```

Note:
> Flags to any warning be come error

With **BUFFER_SIZE** marco

```txt
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=1337 && ./a.out
```

**Valgrind** to check if i have leaks

```txt
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42 && valgrind -s --track-origins=yes  --leak-check=full ./a.out
```

Note:
> -s for summary error no duplicate --track-origins=yes to see uninitialized value --leak-check=full to give you more details leaks

### Example of main

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

File main example to test Bonus part

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

### website and books

What is static variable and how use it from [geeksforgeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/)

What argument pass to read function and what it return [opengroup](https://pubs.opengroup.org/onlinepubs/009604599/functions/read.html)

What is File descriptor in [linux programming interface book](https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf)

How read offset work [IC221 - Systems Programming](https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L09/Class.html) and [linux programming interface book](https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf)

### How I use AI

I don't use AI to much in this project because it was unuseful with my logic i use it just to generated test texts

## Additional

### Explanation algorithm

I save what read in buf and after allocate BUFFER_SIZE and +1 for '\0' it the end, next check if read return 0 that mean i it read whole file if yse and i don't any '\n' free buf and made line pointe to NULL and return any data i still have, if fill not 0 i use strjoin to add string from buf to static variable line i modify strjoin to free old line and buf next check function to know if i have new line in line if yse use substr to store from beginning to new line in buf and use subjoin to store from new line to ending and return buf (aka line) and you need free it in main to don't have leaks.

### Feature list

* Use linked list in Bonus part
* Make logic more simple
* Handle undefine behavior in binary text
