/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/30 12:32:22 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_option(t_point *new_point, t_win *param)
{
	if (param->color.oui == 0)
		return (0x00FFFFFF);
	if (new_point->z >= -2 && new_point->z <= 2)
		return (param->color.a);
	if ((new_point->z > 2 && new_point->z <= 4) || (new_point->z < -2 && new_point->z >= -4))
		return (param->color.b);
	if ((new_point->z > 4 && new_point->z <= 6) || (new_point->z < -4 && new_point->z >= -6))
		return (param->color.c);
	if ((new_point->z > 6 && new_point->z <= 8) || (new_point->z < -6 && new_point->z >= -8))
		return (param->color.d);
	if (new_point->z > 150)
		return (param->color.f);
	return (param->color.e);
}

int			color(char *z, t_win *param, t_point *new_point)
{
	int		i;
	int		n;
	int		sto;
	char	*b;

	b = "123456789ABCDEF";
	i = -1;
	sto = 0;
	if ((z = ft_strchr(z, ',')) != 0 && param->color.oui == 0)
	{
		while (z[i++])
		{
			n = 0;
			while (b[n])
			{
				if (b[n] == z[i] || (n > 8 && z[i] == b[n] + ('a' - 'A')))
					sto += (ft_recursive_power(16, (ft_strlen(z)
									- (i + 1))) * (n + 1));
				n++;
			}
		}
		return (sto);
	}
	return (ft_option(new_point, param));
}

t_point		*new_point(int *i, int n, char *nbr, t_win *param)
{
	t_point		*new_point;

	new_point = (t_point *)malloc(sizeof(t_point) * 1);
	(*i)++;
	new_point->x = *i;
	new_point->y = n;
	new_point->z = ft_atoi(nbr);
	new_point->c = color(nbr, param, new_point);
	new_point->next = NULL;
	new_point->previous = NULL;
	return (new_point);
}

int			check_line(char *line)
{
	char *tmp;

	if (!(tmp = ft_strtrim(line)))
			return (0);
	if (ft_strlen(tmp) < 2)
		return (0);
	return (1);
}

int			create_base(int fd, t_win *param)
{
	char	*line;
	char	**nbr;
	int		n;
	int		i;

	n = 1;
	while (get_next_line(fd, &line) > 0 && check_line(line) != 0)
	{
		i = 0;
		nbr = ft_strsplit(line, ' ');
		while (nbr[i] != NULL)
		{
			if (n == 1 && i == 0)
				param->point = new_point(&i, n, nbr[i], param);
			param->point->next = new_point(&i, n, nbr[i], param);
			param->point->next->previous = param->point;
			param->point = param->point->next;
		}
		n++;
	}
	if (check_line(line) == 0)
		return (0);
	calcul_u_and_o(param, i + 1, n);
	ft_connect_base(param, "yo");
	return (1);
}
