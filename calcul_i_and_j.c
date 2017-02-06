/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_coordonne_and_unit.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:19:05 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/26 16:02:57 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calcul_i_and_j(t_win *param)
{
	param->i.x = param->o.x + (param->unite * cos(param->angle_y));
	param->i.y = param->o.y + (param->unite * sin(param->angle_y) *
		sin(param->angle_x));
	param->j.x = param->o.x - (param->unite * sin(param->angle_y));
	param->j.y = param->o.y + ((param->unite * cos(param->angle_y)) *
		sin(param->angle_x));
}
