#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	int fd2 = open("text2.txt", O_RDONLY);
	int fd3 = open("text3.txt", O_RDONLY);
	int fd4 = open("text4.txt", O_RDONLY);
	int fd5 = open("text5.txt", O_RDONLY);

	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	// line = get_next_line(fd2);
	// printf("%s", line);
	// free(line);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	close(fd);
}
