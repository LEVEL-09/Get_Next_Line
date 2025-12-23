#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);

	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	free(line);

	close(fd);

	line = get_next_line(fd);
	printf("%s", line);
	free(line);


	// while (line)
	// while (line)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }

}
