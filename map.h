/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpulaski <tpulaski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:50:09 by tpulaski          #+#    #+#             */
/*   Updated: 2020/09/29 23:22:51 by tpulaski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "bsq.h"

int     map_read(int fd);

int		map_check_format_str(t_map *map_curr, char *str_curr);

int		map_check_1st_string(t_map *map_curr, char *str_curr);

int		map_check_next_string(t_map *map_curr, char *str_curr);

int		is_empty(char sym);

int		map_scan_x(int x, int y, int max_x);

int		map_scan_y(int x, int y, int max_y);

void	map_max_square_find(int bx, int by);

void	map_find(void);

void	map_plot(void);

void	test(void);

#endif
