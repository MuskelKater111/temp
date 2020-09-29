/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpulaski <tpulaski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:25:18 by tpulaski          #+#    #+#             */
/*   Updated: 2020/09/29 23:15:06 by tpulaski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_point
{
	int		x;
	int		у;
}				t_point;

typedef struct	s_map
{
	char	*data;
	int		size_x;
	int		size_y;
	char	empty;			// символ свободного поля
	char	obstacle;		// символ препядствия
	char	fill;			// символ завполнения поля макс. прямоугольника
	int		max_square_x;	// коорд. макс. квадрата
	int		max_square_y;	// коорд. макс. квадрата
	int		max_square_size;// размер макс. квадрата
}				t_map;

t_map	map;		// глобальная переменная с исходной картой
int		*map_res;	// глобальная переменная с результатами поиска прямоугольников

#endif
