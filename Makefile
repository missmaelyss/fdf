# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 15:51:10 by marnaud           #+#    #+#              #
#    Updated: 2017/01/26 16:04:15 by marnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlx

SRC =  main.c \
	   ft_connect_base.c \
	   calcul_i_and_j.c \
	   calcul_u_and_o.c \
	   create_base.c \
	   libft/libft.a \

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
