/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpulaski <tpulaski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:50:09 by tpulaski          #+#    #+#             */
/*   Updated: 2020/09/29 18:59:41 by tpulaski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "bsq.h"

int		map_read(char *file_name);
	// Author: tpulaski; status: under developing

   // чтение из файла (выделение памяти, присвоение ссылки гл. переменной карты, присвоение размеров карты,
   // заполнениие полей empty, obstacle, fill)

   // read 1st line, atoi for string numbers, get map syms
   // read 2nd str -> get x size, check the data
   // read all others str. and check the data

int		map_check_format_str(t_map *map_curr, char *str_curr);
	// check map format str
	// return": 0 if OK, negative - if bad format

int		map_check_1st_string(t_map *map_curr, char *str_curr);
	// check map 1st str
	// return": 0 if OK, -1 if bad format

int		map_check_next_string(t_map *map_curr, char *str_curr);

int		map_read(char *file_name);

int		map_check(t_map *map_curr);
	// Author: fmira; status: under developing
	// проверка чего-то в карте на правильность формата

char	map_get_val(int x, int y);
	// получение значения пиксела карты по указанным координатам
	// map.data(y * map.size_x + x)

int		is_empty(char sym);
	// определяет - является ли символ свободным пикселом

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

void		test(void);
#endif
