/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:47:20 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/20 16:36:27 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    calcul_coordonne_and_unit(t_win *param, int i, int n)
{
	param->unite = (param->l / 2) / (n + 1) < (param->h / 2) / (i + 1) ? (param->l / 2) / (n + 2) : (param->h / 2) / (2 + i);
	
	param->o.x = param->h / 2;
	//param->o.x = (param->h / 2) - ((i / 2) * param->unite * (cos(param->angle_y) - sin(param->angle_y)));
	param->o.y = param->l / 2;
	//param->o.y = (param->l / 2) + ((n / 2) * param->unite * (cos(param->angle_x) - sin(param->angle_x)));
	param->o.z = 0;
	
	
	param->i.x = param->o.x + (param->unite * cos(param->angle_y));
	param->i.y = param->o.y + (param->unite * sin(param->angle_y) * sin(param->angle_x));
	param->j.x = param->o.x - (param->unite * sin(param->angle_y));
	param->j.y = param->o.y + ((param->unite * cos(param->angle_y)) * sin(param->angle_x));
}

/*t_point		*ft_3d(t_point *point, t_win *param)
{
	double	x;
	double	y;

	x = point->x * (param->i.x - param->o.x) + point->y * (param->j.x - param->o.x) + param->o.x;
	y = point->x * (param->i.y - param->o.y) + point->y * (param->j.y - param->o.y) + param->o.y;
	y -= (param->unite) * point->z * cos(param->angle_x);
	point->x = x;
	point->y = y;
	return (point);
}
*/
t_point		*new_point(int i, int n, char *nbr)
{
	t_point		*new_point;

	new_point = (t_point *)malloc(sizeof(t_point) * 1);
	new_point->x = i + 1;
	new_point->y = n;
	new_point->z = ft_atoi(nbr);
	new_point->next = NULL;
	new_point->previous = NULL;
	return (new_point);
}

int		create_base(int fd, t_win *param)
{
	char	*line;
	char	**nbr;
	int 	n;
	int		i;
	t_point	*point;

	n = 1;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		nbr = ft_strsplit(line, ' ');
		while (nbr[i + 1] != NULL)
		{
			if (n == 1 && i == 0)
				point = new_point(i, n, nbr[i]);
			point->next = new_point(i + 1, n, nbr[i + 1]);
			point->next->previous = point;
			point = point->next;
			i++;
		}
		n++;
	}
	param->tab_point = point;
	calcul_coordonne_and_unit(param, i + 1, n);
	ft_connect_base(param, i + 1, n, "yo");
	return (1);
}
