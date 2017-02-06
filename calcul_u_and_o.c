/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_coordonne_and_unit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:19:05 by marnaud           #+#    #+#             */
/*   Updated: 2017/02/06 15:25:39 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calcul_u_and_o(t_win *param, int i, int n)
{
	param->h = (n + 2) * (500 / n + 2) + 200;
	param->l = (i + 2) * (500 / n + 2);
	param->unite = (param->h) / (n + 2) < (param->l) /
		(i + 2) ? (param->h) / (n + 2) : (param->l) / (2 + i);
	param->unite = param->unite < 1 ? 1 : param->unite;
	param->o.x = param->l / 2;
	param->o.y = param->unite + 200;
	param->o.z = 0;
	calcul_i_and_j(param);
	param->win = mlx_new_window(param->mlx, param->l, param->h, "fdf");
}
