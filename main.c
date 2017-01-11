/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/11 17:14:24 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "fdf.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_esc(int keycode, void *param)
{
	if (keycode == 53)
		exit (0);
	return (1);
}

int		dintoi(double a)
{
	int b;

	b = a;
	printf("a = %f, b = %d\n", a, b);
	return (b);
}

void	relier(t_point a, t_point b, t_win *param, int color)
{
	t_point		v;
	double			max;

	if (a.x == b.x && a.y == b.y)
		return;
	if (a.x >= b.x && a.y >= b.y)
		relier(b, a, param, color);
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

void	ft_3d(t_point *point, t_win *param)
{
	point->x = (param->i.x - param->o.x) * point->x + param->o.x;
//	point->x += (sin(param) * (unite/4)) * point->z;
	point->y = (param->j.y - param->o.y) * point->y + param->o.y;
//	point->y += (cos(angle_rd) * (unite/4)) * point->z;
}

void	create_base(t_win *param)
{
	t_point		a;
	t_point		b;
	t_point		c;
	t_point		d;
/*
	t_point		e;
	t_point		f;
	t_point		g;
	t_point		h;

*/
	a.x = 2;
	a.y = 0;
	a.z = 0;
	
	b.x = 1;
	b.y = 1;
	b.z = 0;
	
	c.x = 2;
	c.y = 2;
	c.z = 0;
	
	d.x = 3;
	d.y = 1;
	d.z = 0;

/*	e.x = 1;
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

*/
	ft_3d(&a, param);
	ft_3d(&b, param);
	ft_3d(&c, param);
	ft_3d(&d, param);
/*	printf("a.x = %f, a.y = %f\n", a.x, a.y);
	printf("b.x = %f, b.y = %f\n", b.x, b.y);
	printf("c.x = %f, c.y = %f\n", c.x, c.y);
	printf("d.x = %f, d.y = %f\n", d.x, d.y);
*//*	ft_3d(&e, angle);
	ft_3d(&f, angle);
	ft_3d(&g, angle);
	ft_3d(&h, angle);
*/	relier(a, b, param, 0x00FF0000);
	relier(b, c, param, 0x000000FF);
	relier(c, d, param, 0x00000FFF);
	relier(d, a, param, 0x0000F000);
	relier(c, a, param, 0x0000FF0F);
	relier(b, d, param, 0x00F0FFF0);
/*	relier(e, g, param, 0x00FF00FF);
	relier(e, f, param, 0x0000FFFF);
	relier(f, h, param, 0x0000FFFF);
	relier(g, h, param, 0x00FFFF00);
	relier(a, e, param, 0x00FF0000);
	relier(b, f, param, 0x000000FF);
	relier(c, g, param, 0x000000FF);
	relier(d, h, param, 0x0000FF00);
*/
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

void	calcul_coordonnee(t_win *param, int angle, int unite)
{
	param->angle = (angle * (M_PI / 2)) / 90;
	param->unite = unite;

//	printf("unite = %d, angle = %f, sin(angle) = %f, cos(angle) = %f\n", param->unite, param->angle, sin())
	param->o.x *= unite;
	param->o.y *= unite;
	param->i.x = param->o.x + unite;
	param->i.y = param->o.y + 0;
	param->j.x = param->o.x + 0;
	param->j.y = param->o.y + (unite * sin(param->angle));
//	printf("%f\n", param->j.y);
	mlx_pixel_put(param->mlx, param->win, param->i.x, param->i.y, 0x00FFFFFF);
	mlx_pixel_put(param->mlx, param->win, param->j.x, param->j.y, 0x00FFFFFF);
	mlx_pixel_put(param->mlx, param->win, param->o.x, param->o.y, 0x00FFFFFF);
}

int main()
{
//	void		*mlx;
//	void		*win;
	t_win		param;
//	int			x;
//	int			y;

	param.o.x = 1;
	param.o.y = 1;
	param.o.z = 0;
	
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 400, 400, "coucou");
//	param.angle = 0;
//	param.unite = 100;
	calcul_coordonnee(&param,  20, 50);
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
	mlx_key_hook(param.win, ft_esc, &param);
	mlx_loop(param.mlx);
	return (0);
}
