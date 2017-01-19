/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:19:32 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/19 17:30:49 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_connect_point(t_point a, t_point b, t_win *param, int color)
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

void     ft_3d(t_point *point, t_win *param)
{
	double  x;
	double  y;

	x = point->x * (param->i.x - param->o.x) + point->y * (param->j.x - param->o.x) + param->o.x;
	y = point->x * (param->i.y - param->o.y) + point->y * (param->j.y - param->o.y) + param->o.y;
	y -= (param->unite) * point->z * cos(param->angle_x);
	point->x = x;
	point->y = y;
	printf("%f, %f, %f\n", point->x, point->y, point->z);
}

void	ft_connect_base(t_win *param, int i, int n, char *pallette)
{
	t_point *point;
	t_point *up;
	double	y_min;

	point = param->tab_point;
	ft_3d(point, param);
	while (point->previous->previous != NULL)
	{
		point = point->previous;
		ft_3d(point, param);
	}
	y_min = point->y;
	while (point->next != NULL)
	{
		if (point->x < i * param->unite)
			ft_connect_point(*point, *(point->next), param, 0x0FFFF00);
		if (point->y > y_min)
		{
			up = point->previous;
			while (up->x != point->x && up->previous != NULL)
				up = up->previous;
			ft_connect_point(*point, *up, param, 0x0FFFF00);
		}
		point = point->next;
	}
}
