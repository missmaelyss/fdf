/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:14:04 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/10 18:45:20 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>

typedef struct	s_win
{
	void	*mlx;
	void	*win;
}				t_win;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
}				t_point;

#endif
