# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 15:51:10 by marnaud           #+#    #+#              #
#    Updated: 2017/01/16 15:32:59 by marnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlx

SRC =  main.c \
	   ft_connect.c \
	   libft/ft_atoi.c

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
