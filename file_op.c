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

#include <fcntl.h>	// the library for 'open' func. and CONST defs.
#include <stdlib.h> // the lib for NULL const and malloc
#include <unistd.h>	// the lib for read, write
#include <stdio.h>	// lib for EOF

#include "bsq.h"
#include "char_string_op.h"  // Потом исправить на хедер, но сначала сождать его
#include "map.h"

int		file_map_format_str_read(t_map *map_curr, int fd, char *buff)
	//	get the t_map pointer, file descriptor fd and read the map format str.
	//	return as int chars num (string length), output the string to *str)
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
	//	get the t_map pointer, file descriptor fd and read the 1st map str.
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
} // *** int file_map_1st_str_read(t_map *map_curr, int fd, char *buff) ***


int		file_map_next_str_read(t_map *map_curr, int fd, char *buff)
	//	get the t_map pointer, file descriptor fd and read the next map str. with len);
{
	int n;

	if (map_curr->size_x > 0)
	{
		n=read(fd, buff, map_curr->size_x + 1);
		if(n != map_curr->size_x + 1)
		{
            write(2, "readerror\n", 10);
			return (-2);  // map-error
		}
		map_check_next_string(map_curr, buff);
		return (0);
	}
	return (-1);
}  // *** int file_map_next_str_read(t_map *map_curr, int fd, char *buff) ***