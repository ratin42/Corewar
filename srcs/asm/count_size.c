/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 17:25:39 by ratin             #+#    #+#             */
/*   Updated: 2019/08/01 15:56:39 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	count_size(t_asm *asmbly)
{
	t_instru	*instru;
	int			y;
	int			i;
	int			count;

	count = 0;
	instru = asmbly->instru;
	while (instru)
	{
		y = -1;
		i = 0;
		while (instru->conv_par != NULL && instru->conv_par[i])
		{
			if (instru->conv_par[i] == ';')
			{
				i++;
				continue ;
			}
			if (y % 2 == 0)
				count++;
			y++;
			i++;
		}
		instru = instru->next;
	}
	asmbly->size = count;
}
