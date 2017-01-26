/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:45:05 by marnaud           #+#    #+#             */
/*   Updated: 2017/01/26 21:00:32 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_montagne(t_win *param)
{
	printf("m");
	param->color.a = 0x0023A441;
	param->color.b = 0x00126525;
	param->color.c = 0x007D4316;
	param->color.d = 0x007D4316;
	param->color.e = 0x00ECE6E1;
	param->color.f = 0x00FEFEFE;

}

void ft_bleu(t_win *param)
{
	printf("b");
	param->color.a = 0x0000FDDB;
	param->color.b = 0x0029BCE1;
	param->color.c = 0x00296CE1;
	param->color.d = 0x002929E1;
	param->color.e = 0x002929E1;
	param->color.f = 0x002929E1;
}

int		ft_color(char *av, t_win *param)
{
	printf("b : %d\n",ft_strcmp(av, "bleu"));
	printf("m : %d\n",ft_strcmp(av, "montagne"));
	printf("mc : %d\n",ft_strcmp(av, "multi-color"));
	if (ft_strcmp(av, "montagne") == 0)
		ft_montagne(param);
	else if (ft_strcmp(av, "bleu") == 0)
		ft_bleu(param);
	else if (ft_strcmp(av, "multi-color") == 0)
	{
	printf("mc");
		param->color.a = 0x00E17F29;
		param->color.b = 0x00DAE129;
		param->color.c = 0x0027BD31;
		param->color.d = 0x0005C4B7;
		param->color.e = 0x000552C4;
		param->color.f = 0x007E05C4;
	}
	else
		return (0);
	param->color.oui = 1;
	return (1);
}
