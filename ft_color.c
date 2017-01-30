/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:45:05 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/30 12:21:30 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_montagne(t_win *param)
{
	param->color.a = 0x0045BA45;
	param->color.b = 0x00196519;
	param->color.c = 0x00094209;
	param->color.d = 0x00493228;
	param->color.e = 0x00755D35;
	param->color.f = 0x00ECDFCA;

}

void ft_bleu(t_win *param)
{
	param->color.a = 0x000041A2;
	param->color.b = 0x001452AF;
	param->color.c = 0x003E77CB;
	param->color.d = 0x00568FE6;
	param->color.e = 0x0083AEF0;
	param->color.f = 0x00B6CFF4;
}

int		ft_color(char *av, t_win *param)
{
	if (ft_strcmp(av, "montagne") == 0)
		ft_montagne(param);
	else if (ft_strcmp(av, "bleu") == 0)
		ft_bleu(param);
	else if (ft_strcmp(av, "multi-color") == 0)
	{
		param->color.a = 0x0071ECDB;
		param->color.b = 0x00EC71D7;
		param->color.c = 0x0071ECA2;
		param->color.d = 0x00E8EC71;
		param->color.e = 0x00B271EC;
		param->color.f = 0x00EC717D;
	}
	else
		return (0);
	param->color.oui = 1;
	return (1);
}
