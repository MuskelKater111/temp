/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string_op.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpulaski <tpulaski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:22:47 by tpulaski          #+#    #+#             */
/*   Updated: 2020/09/29 20:11:42 by tpulaski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_STRING_OP_H
# define CHAR_STRING_OP_H


int		ft_strcmp(char *s1, char *s2);


void	ft_putstr(char *str);


int		ft_atoi(char *str);

void	memcopy(char *src, char *dest, int bytenum);
	// copy of specified byte number

#endif
