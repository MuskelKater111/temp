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
#include <fcntl.h>

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
    int fd;
    int i;
    
    i = 1;
    while (i < argc)
    {
        if (argc == 1)
            fd = 0;
        else
        {
            fd = open(argv[i], O_RDONLY);
            if (fd == -1)
                write (2, "map error\n", 10);
        }
        map_read(fd);
        map_find();
        map_plot();
        write (1, "\n", 1);
        i++;
    }
    

    

//	map_max_square_find(1, 1);

	return (0);
} //*** int main(void) ***
