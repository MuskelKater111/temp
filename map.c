#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"
#include "char_string_op.h"
#include "file_op.h"


int		map_read(int fd)
{
    char    *buff_tmp;
    int     y_curr;

	buff_tmp = (char *)malloc(10000);
    file_map_format_str_read(&map, fd, buff_tmp);
    file_map_1st_str_read(&map, fd, buff_tmp);
    map.data = (char *)malloc(map.size_x * map.size_y);
    memcopy(buff_tmp, map.data, map.size_x);
    free(buff_tmp);
    if (map.data == NULL)
    {
        write(2, "Insufficient memory\n", 20);
        return (-1);
    }
    buff_tmp = (char *)malloc(map.size_x);
    if (buff_tmp == NULL)
    {
        write(2, "Insufficient memory\n", 20);
        return (-1);
    }
    y_curr = 1;
    while (y_curr <= map.size_y - 1)
    {
        file_map_next_str_read(&map, fd, buff_tmp);
        memcopy(buff_tmp, (map.data + map.size_x * y_curr), map.size_x);
        y_curr++;
    }
    free(buff_tmp);
    return (0);
}

int     map_check_format_str(t_map *map_curr, char *str_curr)
{
    int i;
    int n;
    n = ft_atoi(str_curr);
    if (n <= 0)
    {
        write(2, "map erro1\n", 10);
        return (-1);
    }
    i = 0;
    while('0' <= str_curr[i] && str_curr[i] <= '9')
        i++;
    if (*(str_curr + i) < 32 || *(str_curr + i) > 126 || *(str_curr + i) == '\n')
    {
        write(2, "map erro2\n", 10);
        return (-2);
    }
    map_curr->empty = *(str_curr + i);
    if (*(str_curr + i + 1) < 32 || *(str_curr + i + 1) > 126 || *(str_curr + i + 1) == '\n')
    {
        write(2, "map erro3\n", 10);
        return (-3);
    }
    map_curr->obstacle = str_curr[i + 1];
    if (*(str_curr + i + 2) < 32 || *(str_curr + i + 2) > 126 || *(str_curr + i + 2) == '\n')
    {
        write(2, "map erro4\n", 10);
        return (-4);
    }
    map_curr->fill = str_curr[i + 2];
    if ((str_curr[i + 3]) && (str_curr[i + 3] != '\n'))
    {
        write(2, "map erro5\n", 10);
        return (-5);
    }
    map_curr->size_y = n;
    return (n);
}

int		map_check_1st_string(t_map *map_curr, char *str_curr)
{
	int		i;

    i = 0;
	while (str_curr[i])
    {
        if (str_curr[i] != map_curr->empty && str_curr[i] != map_curr->obstacle)
        {
            write(2, "map erro6\n", 10);
            return (-1);
        }
        i++;
    }
    map_curr->size_x = i;
    return (0);
}

int		map_check_next_string(t_map *map_curr, char *str_curr)
{
	int		i;

    i = 0;
	while (!str_curr[i] && i <= map_curr->size_x)
    {
        if (str_curr[i] != map_curr->empty && str_curr[i] != map_curr->obstacle)
        {
            write(2, "map erro7\n", 10);
            return (-1);
        }
        i++;
    }
    return (0);
}

int		map_scan_x(int x, int y, int max_x)
{
    int xp;

    xp = 0;
    while ((*(map.data + y * map.size_x + (x + xp)) != map.obstacle)   &&   (xp < max_x)  && (x + xp < map.size_x) )
        xp++;
    return (xp);
}

int		map_scan_y(int x, int y, int max_y)
{
    int yp;

    yp = 0;
    while ((*(map.data + (y + yp) * map.size_x + x) != map.obstacle)   &&   (yp < max_y)  && (y + yp < map.size_y) )
        yp++;
    return (yp);
}


int     map_max_square_find(int x, int y)
{
    int cp;
    int x_scan_len;
    int y_scan_len;

    cp = 0;
    x_scan_len = map_scan_x(x, y + cp, cp + 1);
    y_scan_len = map_scan_y(x + cp, y, cp + 1);
	while (cp <= map.size_x - 1 && cp <= map.size_y - 1 && x_scan_len > 0 && y_scan_len > 0 \
			&& (x_scan_len == cp + 1)  &&  (y_scan_len == cp + 1))
	{
        cp++;
        x_scan_len = map_scan_x(x, y + cp, cp + 1);
        y_scan_len = map_scan_y(x + cp, y, cp + 1);
	}
    return (cp);
}

void		map_find(void)
{
	int x;
	int y;
    int sq_size;
    
    y = 0;
	while (y <= map.size_y - 1)
	{
		x = 0;
		while  (x <= map.size_x -1)
		{
			sq_size = map_max_square_find(x, y);
            if ( sq_size > map.max_square_size)
            {
                map.max_square_size = sq_size;
                map.max_square_x = x;
                map.max_square_y = y;
            }
            x++;	
		}
		y++;
	}
}


void		map_plot(void)
{
    int x;
    int y;
    
    y = 0;
    while (y <= map.size_y - 1)
    {
        x = 0;
        while  (x <= map.size_x -1)
        {
            if (((x >= map.max_square_x) && (x < map.max_square_x + map.max_square_size)) \
                && (y >= map.max_square_y) && (y < map.max_square_y + map.max_square_size))
                write (1, &map.fill, 1);
            else
                write (1, (map.data + y * map.size_x + x), 1);
            x++;
        }
        write (1, "\n", 1);
        y++;
    }
    free(map.data);
}

int		is_empty(char sym)
{
	if (sym == map.empty)
		return (0);
	else
		return (-1);
}
