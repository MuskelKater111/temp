/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpulaski <tpulaski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 08:49:47 by tpulaski          #+#    #+#             */
/*   Updated: 2020/09/29 23:26:53 by tpulaski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"										// Объявления глобальных вещей
#include "map.h"										// Надо заменить на хедеры  .h (сначала их создать)

#include <stdio.h>	// 4DEBUG
#include <unistd.h>	// 4DEBUG

	
int		main(int argc, char *argv[])
{
	// блок чтения агументов со списком карт, переданных на обработку.
	// тут вызываем map_find(char *file_name_curr); по всему списку аргументов
/*	while (по всем аргументам)
	{
		map_find(char *file_name_curr);
		map_plot(t_map *map_curr);
	}
*/
	
	if (argc == 2)
		map_read(argv[1]);
		map_find();

//	map_max_square_find(1, 1);

	return (0);
} //*** int main(void) ***

/*
4.ox

o..ooo
......
o....o
o.o.oo

*/