#include <fcntl.h>	// the library for 'open' func. and CONST defs.
#include <stdlib.h> // the lib for NULL const and malloc
#include <unistd.h>	// lib for write

#include <stdio.h>	// 4DEBUG

#include "bsq.h"
#include "char_string_op.h"
#include "file_op.h"


int		map_read(char *file_name)
{
   // чтение из файла (выделение памяти, присвоение ссылки гл. переменной карты, присвоение размеров карты,
   // заполнениие полей empty, obstacle, fill)

   // read 1st line, atoi for string numbers, get map syms
   // read 2nd str -> get x size, check the data
   // read all others str. and check the data

	int		fd;
    char    *buff_tmp;
    int     y_curr;

	if (!ft_strcmp(file_name, ""))
		fd = 0;
    else
    	fd = open(file_name, O_RDONLY);
	buff_tmp = (char *)malloc(10000);                       // ПОДУМАТЬ!!!
    file_map_format_str_read(&map, fd, buff_tmp);
    file_map_1st_str_read(&map, fd, buff_tmp);

    map.data = (char *)malloc(map.size_x * map.size_y);

getchar();

    memcopy(buff_tmp, map.data, map.size_x);
    free(buff_tmp);

printf("map.size_x = %d, map.size_y = %d\n", map.size_x, map.size_y);
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
    return (0);
}


/*
	char	*c_temp_map;

	else
	{
		fd = open(file_name, O_RDONLY);
		if (fd < 0)
		{
			write(2, "map error\n", 10);
			return (-1); // file can not be open
		}
	}

	c_temp_map = (char *)malloc(65536);
	if (c_temp_map == NULL)
	{
		write(2, "Insufficient memory\n", 20);
		return (-2);
	}

*/



int     map_check_format_str(t_map *map_curr, char *str_curr)
    // Author: fmira;   Status: DEV.
{
    int i;
    int n;
    n = ft_atoi(str_curr);
    if (n <= 0)
    {
        write(2, "map error\n", 10);
        return (-1);
    }
    i = 0;
    while('0' <= str_curr[i] && str_curr[i] <= '9')
        i++;
    if (*(str_curr + i) < 32 || *(str_curr + i) > 126 || *(str_curr + i) == '\n')
    {
        write(2, "map error\n", 10);
        return (-2);
    }
    map_curr->empty = *(str_curr + i);
    if (*(str_curr + i + 1) < 32 || *(str_curr + i + 1) > 126 || *(str_curr + i + 1) == '\n')
    {
        write(2, "map error\n", 10);
        return (-3);
    }
    map_curr->obstacle = str_curr[i + 1];
    if (*(str_curr + i + 2) < 32 || *(str_curr + i + 2) > 126 || *(str_curr + i + 2) == '\n')
    {
        write(2, "map error\n", 10);
        return (-4);
    }
    map_curr->fill = str_curr[i + 2];
    if ((str_curr[i + 3]) && (str_curr[i + 3] != '\n'))
    {
        write(2, "map error\n", 10);
        return (-5);
    }
    map_curr->size_y = n;
    return (n);
} /*** int map_check_format_str(t_map *map_curr, char *str_curr) ***/

int		map_check_1st_string(t_map *map_curr, char *str_curr)
{
	int		i;

    i = 0;
	while (str_curr[i])
    {
        if (str_curr[i] != map_curr->empty && str_curr[i] != map_curr->obstacle)
        {
            write(2, "map error\n", 10);
            return (-1);
        }
        i++;
    }
    map_curr->size_x = i;
    return (0);
} /*** int map_check_string(t_map *map_curr, char *str_curr) ***/

int		map_check_next_string(t_map *map_curr, char *str_curr)
{
	int		i;

    i = 0;
	while (!str_curr[i] && i <= map_curr->size_x)
    {
        if (str_curr[i] != map_curr->empty && str_curr[i] != map_curr->obstacle)
        {
            write(2, "map error\n", 10);
            return (-1);
        }
        i++;
    }
    return (0);
} /*** int map_check_next_string(t_map *map_curr, char *str_curr) ***/


/*

char	map_get_val(int x, int y);
	// получение значения пиксела карты по указанным координатам
	// map.data(y * map.size_x + x)

int		map_scan_x(int x, int y, char val);
	// ищет вправо от точки икс-игрек значение val и возвращает смещение до найденного пиксела или смещение до края карты, если ничего
	// не нашлось, т. е. показывает сколько свободных пикселов есть вправо.

int		map_scan_y(int x, int y, char val);
	// ищет вниз от точки икс-игрек значение val и возвращает смещение до найденного пиксела или смещение до края карты, если ничего
	// не нашлось, т. е. показывает сколько свободных пикселов есть вниз.

t_point	map_max_rect_find(int x, int y);
	// ищет макс. допустимый пустой прямоугольник для указанной точки левого-вернегно угла

int		map_find(char *file_name_curr);
	// обрабатывает текущую переданную карту на предмет поиска максимального свободного прямоугольника,
	// если имя файла с картой - пустая строка, то читаем карту с консоли
	// по ходу поиска всегда заполнем поля rect_x, rect_y, rect_size_x, rect_size_y.

int		map_max_rect_plot(t_map *map_curr);
	// заполняет символом заполнителя map.fill область на карте

int		map_plot(t_map *map_curr);
	// выводит в станд. поток вывода карту с отрисованным максимальным прямоугольником

int		is_empty(char sym);
	// определяет - является ли символ свободным пикселом
{
	if (sym == t_map.empty)
		return (0);
	else
		return (-1);
}
*/