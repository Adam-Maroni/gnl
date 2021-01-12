
#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
#define FILENAME "tmp"

	char *string;
	int fd;

	string = (char*)malloc(100 * sizeof(*string));
	if ((fd = open(FILENAME, O_RDONLY)) < 0)
	{
		printf("Probeleme lors de l'ouverture du file descriptor");
		return -1;
	}
	get_next_line(fd, &string);
	free(string);
	close(fd);
}
