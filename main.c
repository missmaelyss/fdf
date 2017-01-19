/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/19 17:34:38 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_esc(int keycode, void *param)
{
	if (keycode == 53)
		exit (0);
	return (1);
}

int main(int ac, char **av)
{
	t_win		param;
	int			fd;
	t_point		*tab_point;

	
	fd = open(av[1], O_RDONLY);
	
	param.l = 400;
	param.h = 400;
	
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, param.h, param.l, "coucou");
	
	param.angle_x = (10 * (M_PI / 2)) / 90;
	param.angle_y = (45 * (M_PI / 2)) / 90;

	create_base(fd, &param);
	mlx_pixel_put(param.mlx, param.win, param.i.x, param.i.y, 0x000000FF);
	mlx_pixel_put(param.mlx, param.win, param.j.x, param.j.y, 0x0000FF00);
	mlx_pixel_put(param.mlx, param.win, param.o.x, param.o.y, 0x00FF0000);
//	ft_connect_base(tab_point, "yo");
	mlx_key_hook(param.win, ft_esc, &param);
	mlx_loop(param.mlx);
	return (0);
}
