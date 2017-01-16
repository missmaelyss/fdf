/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:19:32 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/16 14:26:42 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_connect(t_point a, t_point b, t_win *param, int color)
{
	t_point		v;
	double			max;

	if (a.x == b.x && a.y == b.y)
		return;
	if (a.x >= b.x && a.y >= b.y)
		ft_connect(b, a, param, color);
	else
	{
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	max = v.x > v.y ? v.x : v.y;

//	printf("v.x = %f, v.y = %f\nmax = %f\n", v.x, v.y, max);	
	if (max == 0)
		max = 1;
	a.x *= max;
	a.y *= max;
	b.x *= max;
	b.y *= max;
	if (a.x < b.x)
		while (a.x < b.x)
		{
			mlx_pixel_put(param->mlx, param->win, a.x / max, a.y / max, color/*0x00FFFFFF*/);
			a.x += v.x;
			a.y += v.y;
		}
	else
		while (a.y < b.y)
		{
			mlx_pixel_put(param->mlx, param->win, a.x / max, a.y / max, color/*0x00FFFFFF*/);
			a.x += v.x;
			a.y += v.y;
		}
	}
}
