/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/26 20:53:11 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_usage(int i, char *av1, char *av2)
{
	if (i == 1)
		ft_putstr("usage : mlx source_file  [-c [montage][bleu][multi-color]][-s]\n");
	if (i == 0 && (av1 == NULL ||
				ft_strcmp(av1, ft_itoa(ft_atoi(av1))) != 0 ||
	av2 == NULL ||
	ft_strcmp(av2, ft_itoa(ft_atoi(av2))) != 0))
		return (1);
	return (0);
}

int		option(char **av, int ac, t_win *param, char *opt)
{
	int	i;

	i = 1;
	param->color.oui = 0;
	while (i < ac)
	{
		if (ft_strcmp(av[i], opt) == 0)
		{
			if ((ft_strcmp(opt, "-s") == 0 && ft_usage(0, av[i + 1], av[i + 2]) == 1) ||
			(ft_strcmp(opt, "-c") == 0 && av[i + 1] == NULL))
				return (ft_usage(1, NULL, NULL));
			if (ft_strcmp(opt, "-s") == 0)
			{
				param->l = ft_atoi(av[i + 1]);
				param->h = ft_atoi(av[i + 2]);
			}
			if (ft_strcmp(opt, "-c") == 0)
				if (ft_color(av[i + 1], param) == 0)
					ft_usage(1, NULL, NULL);
		}
		i++;
	}
	return (1);
}

void	clean_win(t_win *param)
{
	int x;
	int	y;

	y = 0;
	while (y <= param->h)
	{
		x = 0;
		while (x <= param->l)
		{
			mlx_pixel_put(param->mlx, param->win, x, y, 0);
			x++;
		}
		y++;
	}
}

int		ft_esc(int k, t_win *param)
{
	if (k == 53)
		exit(0);
	if ((k > 122 && k < 127) || k == 69 || k == 78 || k == 33 ||
			k == 30 || k == 36 || k == 258)
	{
		clean_win(param);
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
		ft_connect_base(param, "yo");
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
		return (ft_usage(1, NULL, NULL));
	param.l = 400;
	param.h = 400;
	param.angle_x = (45 * (M_PI / 2)) / 90;
	param.angle_y = (45 * (M_PI / 2)) / 90;
	if (option(av, ac, &param, "-c") == 0 || option(av, ac, &param, "-s") == 0)
		return (0);
	param.mlx = mlx_init();
	if (create_base(fd, &param) == 0)
		return (0);
	mlx_key_hook(param.win, ft_esc, &param);
	mlx_loop(param.mlx);
	return (0);
}
