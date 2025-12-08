#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char buf[11];
	int i;

	read(fd, buf, (size_t)10);

	printf("%s \n", buf);

	close(fd);
}