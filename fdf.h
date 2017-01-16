/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:14:04 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/16 14:30:19 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
}				t_point;

typedef struct	s_win
{
	void	*mlx;
	void	*win;
	double		angle_x;
	double		angle_y;
	t_point	o;
	t_point	i;
	t_point	j;
	t_point	k;
	int		unite;
}				t_win;

void	ft_connect(t_point a, t_point b, t_win *param, int color);

#endif
