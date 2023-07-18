
#include "get_next_line.h"
int main(void)
{
	int		fd;
	char*	str;

	fd = open("read_error.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("fd = %d, in main str = %s\n", fd, str);
	free(str);
	str = get_next_line(fd);
	printf("fd = %d, in main str = %s\n", fd, str);
	free(str);
	str = get_next_line(fd);
	printf("fd = %d, in main str = %s\n", fd, str);
	free(str);
	close(fd);

	printf("---closed--");

	fd = open("read_error.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("fd = %d, in main str = %s\n", fd, str);
	free(str);
	close(fd);
}
