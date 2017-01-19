/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:19:32 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/17 11:18:51 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_connect(t_point a, t_point b, t_win *param, int color)
{
	t_point		v;
	double		max;

	if (a.x == b.x && a.y == b.y)
		return (0);
	if (a.x >= b.x && a.y >= b.y)
		ft_connect(b, a, param, color);
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	max = v.x * v.x > v.y * v.y ? v.x : v.y;
	max = max > 0 ? max : -max;
	v.x /= max;
	v.y /= max;
	while (max > 0)
	{
		mlx_pixel_put(param->mlx, param->win, a.x, a.y, color);
		a.x += v.x;
		a.y += v.y;
		max--;
	}
	return (1);
}
