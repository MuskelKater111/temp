#include "bsq.h"

int		map_res_create(t_map *map);
	// выделяет создаёт динам. буфер int'ов по размерам карты

void	map_res_get_val(int x, int y, int *size_x, int *size);
	// читает из map_res значение свободного прямоугольника на карте для координат его левого верхнего угла
	// y * map.size_x*2*sizeof(int) + x*2*sizeof(int);

void	map_res_set_val(int x, int y, int *size_x, int *size);
	// записывает в map_res значение свободного прямоугольника на карте для координат его левого верхнего угла
	// y * map.size_x*2*sizeof(int) + x*2*sizeof(int);
