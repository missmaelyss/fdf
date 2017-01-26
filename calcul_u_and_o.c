/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_coordonne_and_unit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:19:05 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/26 16:13:51 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calcul_u_and_o(t_win *param, int i, int n)
{
	if (param->l / 2 < n + 1 && param->h / 2 < i + 1)
	{
		param->l = (n + 1) * 2;
		param->h = (i + 1) * 2;
	}
	param->unite = (param->l / 2) / (n + 1) < (param->h / 2) /
		(i + 1) ? (param->l / 2) / (n + 2) : (param->h / 2) / (2 + i);
	param->unite = param->unite < 1 ? 1 : param->unite;
	param->o.x = param->h / 2;
	param->o.y = param->l / 2;
	param->o.z = 0;
	calcul_i_and_j(param);
	param->win = mlx_new_window(param->mlx, param->h, param->l, "fdf");
}
