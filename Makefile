# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marnaud <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/07 15:51:10 by marnaud           #+#    #+#              #
#    Updated: 2017/02/06 14:37:12 by marnaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC =  main.c \
	   ft_connect_base.c \
	   ft_color.c \
	   calcul_i_and_j.c \
	   calcul_u_and_o.c \
	   create_base.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@(cd libft && $(MAKE))
	@(cd minilibx && $(MAKE))
	gcc -o $(NAME) $(SRC) libft/libft.a -lmlx -framework OpenGL -framework AppKit

clean:
	@(cd libft && $(MAKE) $@)
	@(cd minilibx && $(MAKE) $@)
	rm -f $(OBJ)

fclean: clean
	@(cd libft && $(MAKE) $@)
	rm -f $(NAME)

re: fclean all

.PHONY: $(NAME)
