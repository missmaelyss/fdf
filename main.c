/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/06 16:27:27 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_usage(void)
{
	ft_putstr("usage : mlx source_file ");
	ft_putstr("[-c [montagne][bleu][multi-color]][-s]\n");
	return (0);
}

int		option(char **av, int ac, t_win *param, char *opt)
{
	int	i;

	i = ac - 1;
	while (ac > 0)
	{
		if (ft_strcmp(av[ac - 1], opt) == 0)
		{
			if ((ft_strcmp(opt, "-c") == 0 && av[ac] == NULL))
				return (ft_usage());
			if (ft_strcmp(opt, "-c") == 0)
				if (ft_color(av[ac], param) == 0)
					return (ft_usage());
			i -= 2;
		}
		ac--;
	}
	if (i != 1)
		return (ft_usage());
	return (1);
}

int		ft_esc(int k, t_win *param)
{
	if (k == 53)
		exit(0);
	if ((k > 122 && k < 127) || k == 69 || k == 78 || k == 33 ||
			k == 30 || k == 36 || k == 258)
	{
		mlx_clear_window(param->mlx, param->win);
		param->o.x -= k == 123 ? param->unite : 0;
		param->o.x += k == 124 ? param->unite : 0;
		param->o.y += k == 125 ? param->unite : 0;
		param->o.y -= k == 126 ? param->unite : 0;
		param->unite *= k == 69 ? 2 : 1;
		param->angle_y += k == 33 ? (M_PI / 50) : 0;
		param->angle_y -= k == 30 ? (M_PI / 50) : 0;
		param->angle_x -= k == 36 ? (M_PI / 50) : 0;
		param->angle_x += k == 258 ? (M_PI / 50) : 0;
		if (k == 78 && param->unite >= 2)
			param->unite /= 2;
		calcul_i_and_j(param);
		ft_connect_base(param);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_win		param;
	int			fd;
	int			n;
	t_point		*tab_point;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_usage());
	param.angle_x = (45 * (M_PI / 2)) / 90;
	param.angle_y = (45 * (M_PI / 2)) / 90;
	param.color.oui = 0;
	if (option(av, ac, &param, "-c") == 0)
		return (0);
	param.mlx = mlx_init();
	if (create_base(fd, &param) == 0)
		return (0);
	mlx_key_hook(param.win, ft_esc, &param);
	mlx_loop(param.mlx);
	return (0);
}
