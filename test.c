#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "bsq.h"
#include "char_string_op.h"
#include "file_op.h"
#include "map.h"

/*
int	testfr(int fd, char *buff, int *len)
{
	char	c;
	int		n;

		*len = 0;
		n = read(fd, &c, 1);
		while ((n > 0) && (c != '\n') && (*len < 20))
		{
write(1, "\n", 1);
write(1, &c, 1);
			*(buff + *len) = c;
			*len = *len + 1;
printf("len = %d, buff + *len = %p, *(buff + *len) = %s\n", *len, buff + *len, buff);
			n = read(fd, &c, 1);
		}

	return (0);
}
*/


/*
{
	char	c;
	int		n;

	if (mode == 1)
	{
		*len = 0;
		n = read(fd, &c, 1);
		while ((n > 0) && (c != '\n') && (*len < 20))
		{
			write(1, "\n", 1);
			write(1, &c, 1);
printf("len = %d, buff + *len = %p, *(buff + *len) = %s\n", *len, buff + *len, buff);
			*(buff + *len) = c;
			*len = *len + 1;
			n = read(fd, &c, 1);
		}
	}
*/

/*
{
	char	c;
	int		n;

	if (mode == 1)
	{
		*len = 0;
		n = read(fd, &c, 1);
		while ((n > 0) && (c != '\n') && (*len < 20))
		{
write(1, "\n", 1);
write(1, &c, 1);
			*(buff + *len) = c;
			*len = *len + 1;
printf("len = %d, buff + *len = %p, *(buff + *len) = %s\n", *len, buff + *len, buff);
			n = read(fd, &c, 1);
		}
	}
	return (0);
}
*/




int	main(void)
{
	t_map	map;
	char *sss = "55.\box";

	map.empty = '.';
	map.obstacle = 'o';
	map.fill = 'x';

	printf("map_check_format_str res: %d\n", map_check_format_str(&map, sss));

	test();
/*
	fd = open("testmap.txt", O_RDONLY);

	char *buf;
	buf = (char *)malloc(10000);
	testfr(fd, buf, &len);

	printf ("buf: %s", buf);
	return (0);
*/
}