/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpulaski <tpulaski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:41:40 by tpulaski          #+#    #+#             */
/*   Updated: 2020/09/29 23:19:18 by tpulaski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "bsq.h"
#include "char_string_op.h"
#include "map.h"

int		file_map_format_str_read(t_map *map_curr, int fd, char *buff)
{
	int i;
	int n;

	i = 0;
	n = read(fd, (buff + i), 1);
    
	while ((n > 0) && (*(buff + i) != '\n'))
	{
		i++;
		n = read(fd, (buff + i), 1);
	}
	map_check_format_str(map_curr, buff);
	return (0);
}

int		file_map_1st_str_read(t_map *map_curr, int fd, char *buff)
{
	char	c;
	int		n;
	int		i;

	i = 0;
	n = read(fd, &c, 1);
	while ((n > 0) && (c != '\n'))
	{
		*(buff + i) = c;
		i++;
		n = read(fd, &c, 1);
	}
	map_check_1st_string(map_curr, buff);
	return (0);
}
int		file_map_next_str_read(t_map *map_curr, int fd, char *buff)
{
	int n;
    
	if (map_curr->size_x > 0)
	{
		n=read(fd, buff, map_curr->size_x + 1);
		if(n != map_curr->size_x + 1)
		{
            write(2, "readerror\n", 10);
			return (-2);
		}
		map_check_next_string(map_curr, buff);
		return (0);
	}
	return (-1);
}
