/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpulaski <tpulaski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 10:41:40 by tpulaski          #+#    #+#             */
/*   Updated: 2020/09/29 18:47:55 by tpulaski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_OP_H
# define FILE_OP_H

#include "bsq.h"

int		file_map_format_str_read(t_map *map_curr, int fd, char *buff);
	//	get the t_map pointer, file descriptor fd and read the map format str.
	//	return as int chars num (string length), output the string to *str)


int		file_map_1st_str_read(t_map *map_curr, int fd, char *buff);
	//	get the t_map pointer, file descriptor fd and read the 1st map str.


int		file_map_next_str_read(t_map *map_curr, int fd, char *buff);
	//	get the t_map pointer, file descriptor fd and read the next map str. with len stored in map.size_x)
	
#endif

