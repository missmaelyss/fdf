/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:19:32 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/23 17:34:14 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_connect_point(t_point a, t_point b, t_win *param, int color)
{
	t_point		v;
	double		max;

	if (a.x == b.x && a.y == b.y)
		return (0);
	if (a.x >= b.x && a.y >= b.y)
		ft_connect_point(b, a, param, color);
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

t_point		ft_3d(t_point *point, t_win *param)
{
	t_point	d_point;

	d_point.x = point->x * (param->i.x - param->o.x) +
		point->y * (param->j.x - param->o.x) + param->o.x;
	d_point.y = param->o.y * point->y;
	d_point.y = point->x * (param->i.y - param->o.y) +
		point->y * (param->j.y - param->o.y) + param->o.y;
	d_point.y -= (param->unite) * point->z * cos(param->angle_x);
	d_point.z = point->z;
	return (d_point);
}

void		ft_connect_base(t_win *param, int i, int n, char *pallette)
{
	t_point *point;
	t_point *up;

	point = param->point;
	while (point->previous->previous != NULL)
		point = point->previous;
	while (!(point->x == i && point->y == n))
	{
		if (point->y == point->next->y && point->next != NULL)
			ft_connect_point(ft_3d(point, param),
					ft_3d(point->next, param), param, 0x0FFFF00);
		if (point->y > 1)
		{
			up = point->previous;
			while (up->x != point->x && up->previous != NULL)
				up = up->previous;
			ft_connect_point(ft_3d(point, param),
					ft_3d(up, param), param, 0x0FFFF00);
		}
		point = point->next;
	}
	up = point->previous;
			while (up->x != point->x && up->previous != NULL)
				up = up->previous;
			ft_connect_point(ft_3d(point, param),
					ft_3d(up, param), param, 0x0FFFF00);
}
