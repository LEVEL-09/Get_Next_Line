# Get Next Line

This project has been created as part of the 42 curriculum by **_mkhoubaz_**

## Description

This project in **C** about created **Get_next_line** functionto read from file descriptor use function **read()** and retrun one line or return NULL if any error hapind or nothing else to read use **tatic variable** without leaks.

## Instructions

To run this code use **CC** compiler and it flags `-Wall -Wextra -Werror`

```txt
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c && ./a.out
```

> Flags to any warning be come error

With **BUFFER_SIZE** marco

```txt
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=1337 && ./a.out
```

**Valgrind** to check if i have leaks

```txt
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42 && valgrind -s --track-origins=yes  --leak-check=full ./a.out
```

> -s for summary error no duplicate --track-origins=yes to see uninsailized value --leak-check=full to give you more details leaks

## Resources

What is static varibles and how use it from [geeksforgeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/)

What is File descriptor in [linux programming interface book](https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf)

How read offset work [IC221 - Systems Programming](https://www.usna.edu/Users/cs/wcbrown/courses/IC221/classes/L09/Class.html) and [linux programming interface book](https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf)
