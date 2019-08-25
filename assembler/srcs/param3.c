/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:08:52 by syzhang           #+#    #+#             */
/*   Updated: 2019/08/26 00:32:43 by ratin            ###   ########.fr       */
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

void			print_erro_param(t_asm *asmbly, char *str, int line, int error)
{
	if (error == 1)
		ft_putstr_fd("Lexical error for param [", 2);
	else if (error == 2)
		ft_putstr_fd("bad number of parameter at [", 2);
	ft_putnbr(line);
	ft_putchar(':');
	ft_putnbr(0);
	ft_putstr_fd("] ->", 2);
	ft_putstr_fd(str, 2);
	ft_putchar('\n');
	quit_prog(asmbly);
}
