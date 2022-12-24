#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		idx;
	int		fd;
	char	*str;

	idx = 1;
	fd = open("giant_line_nl.txt", O_RDWR);
	while (idx < 100)
	{
		fd = open("giant_line_nl.txt", O_RDWR);
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		str = get_next_line(fd);
		printf("%d: <%s>\n", idx, str);
		free(str);
		idx++;
		close(fd);
	}
	return (0);
}