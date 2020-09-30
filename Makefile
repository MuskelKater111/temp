# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpulaski <tpulaski@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 13:46:31 by tpulaski          #+#    #+#              #
#    Updated: 2020/09/29 00:20:02 by tpulaski         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= BSQ
HEAD	= *.h
SRCS    = main.c map.c char_string_op.c file_op.c
OBJS    = *.o
CFLAGS	= -Wall -Wextra -Werror
U_HEAD	= -I $(HEAD)

${NAME}:
	gcc -c $(SRCS)
	gcc $(OBJS) -o $(NAME)

all: $(NAME)

debug: 
	gcc -c $(SRCS)
	gcc $(OBJS) -o $(NAME)

clean:
	rm -f ${OBJS}

fclean:     clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re