/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:27:45 by ratin             #+#    #+#             */
/*   Updated: 2019/08/26 00:33:54 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				nbr_prm(t_asm *asmbly, t_instru *instru, char *str, int line)
{
	t_param		*last;
	int			i;

	last = instru->param;
	i = 0;
	while (last)
	{
		last = last->next;
		i++;
	}
	if (i != instru->nbr_of_params)
		print_erro_param(asmbly, str, line, 2);
	return (0);
}

void			p_error(t_asm *asmbly, t_param *param, int line, t_instru *ins)
{
	ft_putstr_fd("bad parameter at line: ", 2);
	ft_putnbr(line);
	ft_putstr_fd(" for instruction ", 2);
	ft_putstr_fd(ins->opcode, 2);
	ft_putstr_fd(".\nGot ", 2);
	if (param->type == 1)
		ft_putstr_fd("register", 2);
	if (param->type == 2)
		ft_putstr_fd("direct", 2);
	if (param->type == 4)
		ft_putstr_fd("indirect", 2);
	ft_putstr_fd("\n", 2);
	quit_prog(asmbly);
}

int				check_para(int para_index, int i, t_param *last)
{
	extern t_op	g_op_tab[17];
	int			checker;

	if (para_index == 1)
		checker = g_op_tab[i].type_of_param.param1;
	if (para_index == 2)
		checker = g_op_tab[i].type_of_param.param2;
	if (para_index == 3)
		checker = g_op_tab[i].type_of_param.param3;
	if (checker == 1 || checker == 2 || checker == 4)
	{
		if (last->type != checker)
			return (-1);
	}
	else
	{
		if (last->type > checker)
			return (-1);
	}
	return (0);
}

int				check_type(t_asm *asmbly, t_instru *instru, int line)
{
	t_param		*last;
	int			i;
	int			para_index;

	i = find_op_index(instru->opcode);
	para_index = 1;
	last = instru->param;
	while (last)
	{
		if (check_para(para_index, i, last) == -1)
			p_error(asmbly, last, line, instru);
		para_index++;
		last = last->next;
	}
	return (0);
}

void			check_params_error(t_asm *asmbly, char *str, int line)
{
	t_instru	*current;

	if (!(current = find_instru(asmbly, line)))
		current = get_last_instru(asmbly);
	nbr_prm(asmbly, current, str, line);
	check_type(asmbly, current, line);
}
