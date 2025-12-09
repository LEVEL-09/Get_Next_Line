#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFFER_SIZE 5

# include <stdlib.h>
# include <unistd.h>

char *get_next_line(int fd);

#endif