#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// void print_binary_line(char *line, int len) {
//     for (int i = 0; i < len; i++) {
//         if (line[i] == '\0') 
//             printf("\\0"); // Visualize the null byte
//         else 
//             printf("%c", line[i]);
//     }
//     printf("\n");
// }

int main() {
    int fd = open("binary_test.txt", O_RDONLY);

	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

    close(fd);
}
