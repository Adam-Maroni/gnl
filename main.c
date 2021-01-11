
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	#define FILENAME "tmp"
	char *string;	
	int fd;
	
	string = (char*)malloc(10*sizeof(*string));
	if(fd = open(FILENAME, O_RDWR) < 0)
		return -1;
	printf("%d",get_next_line(fd , &string));
	free(string);
	close(fd);
}
