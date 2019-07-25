/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:08:52 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/25 04:45:57 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		register_range(int value, int min, int max)
{
	if (value >= min && value <= max)
		return (1);
	return (0);
}

int				is_register(char *param)
{
	if (*param == 'r' && ft_str_is_numeric(param + 1)
		&& register_range(ft_atoi(param + 1), 1, REG_NUMBER))
		return (T_REG);
	return (0);
}

int				find_op_index(char *opcode)
{
	extern t_op	g_op_tab[17];
	int			i;

	i = 0;
	while (g_op_tab[i].name != 0)
	{
		if (ft_strcmp(g_op_tab[i].name, opcode) == 0)
			break ;
		i++;
	}
	return (i);
}
