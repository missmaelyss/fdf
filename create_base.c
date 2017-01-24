/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/24 17:42:21 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calcul_coordonne_and_unit(t_win *param, int i, int n)
{
	param->unite = (param->l / 2) / (n + 1) < (param->h / 2) /
		(i + 1) ? (param->l / 2) / (n + 2) : (param->h / 2) / (2 + i);
	param->o.x = param->h / 2;
	param->o.y = param->l / 2;
	param->o.z = 0;
	param->i.x = param->o.x + (param->unite * cos(param->angle_y));
	param->i.y = param->o.y + (param->unite * sin(param->angle_y) *
		sin(param->angle_x));
	param->j.x = param->o.x - (param->unite * sin(param->angle_y));
	param->j.y = param->o.y + ((param->unite * cos(param->angle_y)) *
		sin(param->angle_x));
}

int			color(char *z)
{
	int		i;
	int		n;
	int		sto;
	char	*b;

	b = "123456789ABCDEF";
	i = -1;
	sto = 0;
	if ((z = ft_strchr(z, ',')) != 0)
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
	return (0x00FFFFFF);
}

t_point		*new_point(int i, int n, char *nbr)
{
	t_point		*new_point;
	char		*c;

	new_point = (t_point *)malloc(sizeof(t_point) * 1);
	new_point->x = i + 1;
	new_point->y = n;
	new_point->z = ft_atoi(nbr);
	new_point->c = color(nbr);
	new_point->next = NULL;
	new_point->previous = NULL;
	return (new_point);
}

int			create_base(int fd, t_win *param)
{
	char	*line;
	char	**nbr;
	int		n;
	int		i;

	n = 1;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		nbr = ft_strsplit(line, ' ');
		while (nbr[i + 1] != NULL)
		{
			if (n == 1 && i == 0)
				param->point = new_point(i, n, nbr[i]);
			param->point->next = new_point(i + 1, n, nbr[i + 1]);
			param->point->next->previous = param->point;
			param->point = param->point->next;
			i++;
		}
		n++;
	}
	calcul_coordonne_and_unit(param, i + 1, n);
	ft_connect_base(param, i + 1, n - 1, "yo");
	return (1);
}
