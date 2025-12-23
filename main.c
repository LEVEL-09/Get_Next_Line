#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("text2.txt", O_RDWR);
	// if (fd < 0)
	// 	exit(2);

	char	*line;

	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);

	// close(fd);

	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);


	for (int i =0; i < 3000; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}

	// while (line)
	// while (line)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }

}
