/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/10 19:34:44 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>

int	my_key_ft(int keycode, void *param)
{
//	printf("key event %d\n", keycode);
//	mlx_pixel_put(((t_win *)param)->mlx, ((t_win *)param)->win, 50 + keycode, 50 + keycode, 0x000000FF);
	if (keycode == 53)
		exit (0);
	return (0);
}

void	relier(t_point a, t_point b, t_win *param, int color)
{
	t_point		v;
	int			max;

	if (a.x == b.x && a.y == b.y)
		return;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	max = v.x > v.y ? v.x : v.y;
//	printf("max = %d\nv.x = %d\nv.y = %d\nv.x /= max = %d\nv.y /= max = %d\n", max, v.x, v.y, v.x / max, v.y / max);
	
	if (max == 0)
		max = 1;
	a.x *= max;
	a.y *= max;
	b.x *= max;
	b.y *= max;
	while (a.x != b.x || a.y != b.y)
	{
		mlx_pixel_put(param->mlx, param->win, a.x / max, a.y / max, color/*0x00FFFFFF*/);
		a.x += v.x;
		a.y += v.y;
	}
}

void	ft_3d(t_point *point, int angle_dg)
{
	int			unite;
	double		angle_rd;

	unite = 20;
	angle_rd = (angle_dg * (M_PI / 4)) / 45;
	point->x *= unite;
	point->x += (sin(angle_rd) * unite) * point->z - 3;
	point->y *= unite;
	point->y += (cos(angle_rd) * unite) * point->z - 3;
}

void	create_base(t_win *param)
{
	int			angle;
	t_point		a;
	t_point		b;
	t_point		c;
	t_point		d;

	t_point		e;
	t_point		f;
	t_point		g;
	t_point		h;


	angle = 45;
	
	a.x = 1;
	a.y = 1;
	a.z = 0;
	
	b.x = 1;
	b.y = 2;
	b.z = 0;
	
	c.x = 2;
	c.y = 1;
	c.z = 0;
	
	d.x = 2;
	d.y = 2;
	d.z = 0;

	e.x = 1;
	e.y = 1;
	e.z = 1;
	
	f.x = 1;
	f.y = 2;
	f.z = 1;
	
	g.x = 2;
	g.y = 1;
	g.z = 1;
	
	h.x = 2;
	h.y = 2;
	h.z = 1;


	ft_3d(&a, angle);
	ft_3d(&b, angle);
	ft_3d(&c, angle);
	ft_3d(&d, angle);
	ft_3d(&e, angle);
	ft_3d(&f, angle);
	ft_3d(&g, angle);
	ft_3d(&h, angle);
	relier(a, c, param, 0x00FF0000);
	relier(a, b, param, 0x000000FF);
	relier(b, d, param, 0x000000FF);
	relier(c, d, param, 0x0000FF00);
	relier(e, g, param, 0x00FF00FF);
	relier(e, f, param, 0x0000FFFF);
	relier(f, h, param, 0x0000FFFF);
	relier(g, h, param, 0x00FFFF00);
	relier(a, e, param, 0x00FF0000);
	relier(b, f, param, 0x000000FF);
	relier(c, g, param, 0x000000FF);
	relier(d, h, param, 0x0000FF00);

/*	y = 50;
	while (y<150)
	{
		x = 50;
		while (x<150)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
*/	
}

int main()
{
//	void		*mlx;
//	void		*win;
	t_win		param;
//	int			x;
//	int			y;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 400, 400, "coucou");
/*	y = 50;
	while (y<150)
	{
		x = 50;
		while (x<150)
		{
			mlx_pixel_put(param.mlx, param.win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
*/	create_base(&param);
	mlx_key_hook(param.win, my_key_ft, &param);
	mlx_loop(param.mlx);
	return (0);
}
