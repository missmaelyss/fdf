/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/24 17:46:04 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_usage(int i, char *av1, char *av2)
{
	if (i == 1)
	{
		ft_putstr("usage : mlx source_file [-a int angle_1 int angle_2]");
		ft_putstr(" [-s int height int width]\n");
	}
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
	while (i < ac)
	{
		if (ft_strcmp(av[i], opt) == 0)
		{
			if (ft_usage(0, av[i + 1], av[i + 2]) == 1)
				return (ft_usage(1, NULL, NULL));
			if (ft_strcmp(opt, "-s") == 0)
			{
				param->l = ft_atoi(av[i + 1]);
				param->h = ft_atoi(av[i + 2]);
			}
			if (ft_strcmp(opt, "-a") == 0)
			{
				param->angle_x = (ft_atoi(av[i + 1]) * (M_PI / 2)) / 90;
				param->angle_y = (ft_atoi(av[i + 2]) * (M_PI / 2)) / 90;
			}
		}
		i++;
	}
	return (1);
}

int		ft_esc(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
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
	if (option(av, ac, &param, "-a") == 0 || option(av, ac, &param, "-s") == 0)
		return (0);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, param.h, param.l, "coucou");
	create_base(fd, &param);
	mlx_key_hook(param.win, ft_esc, &param);
	mlx_loop(param.mlx);
	return (0);
}
