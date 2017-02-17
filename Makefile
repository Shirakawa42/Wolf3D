# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/26 20:45:05 by zadrien           #+#    #+#              #
#    Updated: 2017/02/03 13:15:23 by lvasseur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: make all clean fclean re

NAME = Wolf3D

all : $(NAME)

$(NAME):
	gcc -o $(NAME) **/*.c -L.. -lmlx -lbsd -L/usr/lib -lXext -lX11 -lm

clean :
	rm -f **/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all
