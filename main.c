/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/16 16:21:52 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_esc(int keycode, void *param)
{
	if (keycode == 53)
		exit (0);
	return (1);
}

/*int		dintoi(double a)
{
	int b;

	b = a;
	printf("a = %f, b = %d\n", a, b);
	return (b);
}
*/
/*void	relier(t_point a, t_point b, t_win *param, int color)
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
			mlx_pixel_put(param->mlx, param->win, a.x / max, a.y / max, color);
			a.x += v.x;
			a.y += v.y;
		}
	else
		while (a.y < b.y)
		{
			mlx_pixel_put(param->mlx, param->win, a.x / max, a.y / max, color);
			a.x += v.x;
			a.y += v.y;
		}
	}
}
*/
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
	a.x = 0;
	a.y = 0;
	a.z = 0;
	
	b.x = 1;
	b.y = 0;
	b.z = 0;
	
	c.x = 1;
	c.y = 1;
	c.z = 0;
	
	d.x = 0;
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
*//*	ft_connect(a, b, param, 0x00FF0000);
	ft_connect(b, c, param, 0x000000FF);
	ft_connect(c, d, param, 0x00000FFF);
	ft_connect(d, a, param, 0x0000F000);
	ft_connect(c, a, param, 0x0000FF0F);
	ft_connect(b, d, param, 0x00F0FFF0);
*//*	relier(e, g, param, 0x00FF00FF);
	relier(e, f, param, 0x0000FFFF);
	relier(f, h, param, 0x0000FFFF);
	relier(g, h, param, 0x00FFFF00);
	relier(a, e, param, 0x00FF0000);
	relier(b, f, param, 0x000000FF);
	relier(c, g, param, 0x000000FF);
	relier(d, h, param, 0x0000FF00);
*/
	ft_connect(param->i, param->o, param, 0x000000FF);
	ft_connect(param->o, param->j, param, 0x0000FF00);
	ft_connect(param->j, param->i, param, 0x00FF0000);
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

void	calcul_coordonnee(t_win *param, int angle_x, int angle_y, int unite)
{
	param->angle_x = (angle_x * (M_PI / 2)) / 90;
	param->angle_y = (angle_y * (M_PI / 2)) / 90;
	param->unite = unite;

//	printf("unite = %d, angle = %f, sin(angle) = %f, cos(angle) = %f\n", param->unite, param->angle, sin())
	param->o.x *= unite;
	param->o.y *= unite;
	param->i.x = param->o.x + (unite * cos(param->angle_y));
	param->i.y = param->o.y + (unite * sin(param->angle_y) * sin(param->angle_x));
	param->j.x = param->o.x - (unite * sin(param->angle_y));
	param->j.y = param->o.y /*+ (unite * sin(param->angle_x)*/ + ((unite * cos(param->angle_y)) * sin(param->angle_x));
	printf("o.x = %f, o.y = %f, i.x = %f, i.y = %f, j.x = %f, j.y =%f\n", param->o.x, param->o.y, param->i.x, param->i.y, param->j.x, param->j.y);
//	mlx_pixel_put(param->mlx, param->win, param->i.x, param->i.y, 0x00FFFFFF);
//	mlx_pixel_put(param->mlx, param->win, param->j.x, param->j.y, 0x00FFFFFF);
//	mlx_pixel_put(param->mlx, param->win, param->o.x, param->o.y, 0x00FFFFFF);
}

int main(int ac, char **av)
{
//	void		*mlx;
//	void		*win;
	t_win		param;
	int			x;

	param.o.x = 2;
	param.o.y = 2;
	param.o.z = 0;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 400, 400, "coucou");
//	param.angle = 0;
//	param.unite = 100;
		calcul_coordonnee(&param, ft_atoi(av[1]), ft_atoi(av[2]), 50);
		mlx_pixel_put(param.mlx, param.win, param.i.x, param.i.y, 0x000000FF);
		mlx_pixel_put(param.mlx, param.win, param.j.x, param.j.y, 0x0000FF00);
		mlx_pixel_put(param.mlx, param.win, param.o.x, param.o.y, 0x00FF0000);
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
