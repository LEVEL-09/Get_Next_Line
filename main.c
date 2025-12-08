#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	int fd2 = open("text2.txt", O_RDONLY);

	char buf[99];

	int retur = read(fd, buf, (size_t)5);

	printf("%s \n", buf);

	read(fd2, buf+5, (size_t)5);

	printf("%s \n", buf);

	close(fd);
}