# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 15:51:10 by marnaud           #+#    #+#              #
#    Updated: 2017/01/19 14:15:34 by marnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlx

SRC =  main.c \
	   ft_connect_base.c \
	   create_base.c \
	   libft/libft.a \
	   get_next_line/get_next_line.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME)
