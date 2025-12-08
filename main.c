#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char buf[99999];
	int i;

	int retur = read(fd, buf, (size_t)14);

	printf("retrun: %d \n", retur);
	
	printf("%s \n", buf);

	close(fd);
}