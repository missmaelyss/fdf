/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:14:04 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/26 16:03:27 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct	s_point
{
	int				n;
	double			x;
	double			y;
	double			z;
	int				c;
	struct s_point	*next;
	struct s_point	*previous;
}				t_point;

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	int		l;
	int		h;
	double		angle_x;
	double		angle_y;
	t_point	o;
	t_point	i;
	t_point	j;
	t_point	*point;
	double	unite;
}				t_win;

void		calcul_u_and_o(t_win *param, int i, int n);
void		calcul_i_and_j(t_win *param);
void		ft_connect_base(t_win *a, char *color);
int			create_base(int fd, t_win *param);

#endif
