/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpulaski <tpulaski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:22:47 by tpulaski          #+#    #+#             */
/*   Updated: 2020/09/29 20:28:43 by tpulaski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>						// 4DEBUG

int		ft_strcmp(char *s1, char *s2)
{
	int i_cmp;
	int i;

	i = 0;
	while (s1[i] != 0x00 && s2[i] != 0x00 && s1[i] == s2[i])
	{
		i++;
	}
	i_cmp = s1[i] - s2[i];
	return (i_cmp);
}

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_atoi(char *str)
{
	int c[2];
	int i;

	c[0] = 1;
	c[1] = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			c[0] = c[0] * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		c[1] = c[1] * 10 + str[i] - '0';
		i++;
	}
	return (c[1] * c[0]);
}

void	memcopy(char *src, char *dest, int bytenum)
	// copy of specified byte number
{
	int		i;

	i = 0;
	while (i < bytenum)
	{

printf("i = %d, src[i] = %c\n", i, *(src + i));


		*(dest + i) = *(src + i);
		i++;
	}
}