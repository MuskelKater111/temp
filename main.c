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

#include "bsq.h"
#include "map.h"
#include <fcntl.h>
#include <unistd.h>

	
int		main(int argc, char *argv[])
{
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
	return (0);
}
