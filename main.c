#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);

	char *line;
	
	line = get_next_line(fd);
	while (line)
	{	
		if(line == NULL)
			break ;
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);

	// // line = get_next_line(fd);
	// // printf("%s", line);
	// // free(line);

	// // line = get_next_line(fd);
	// // printf("%s", line);
	// // free(line);

	close(fd);
}
