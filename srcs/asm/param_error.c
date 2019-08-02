/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:27:45 by ratin             #+#    #+#             */
/*   Updated: 2019/08/02 07:15:53 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_erro_param(char *str, int line, int error)
{
	if (error == 1)
		ft_putstr("Lexical error for param [");
	else if (error == 2)
		ft_putstr("bad number of parameter at [");
	ft_putnbr(line);
	ft_putchar(':');
	ft_putnbr(0);
	ft_putstr("] ->");
	ft_putstr(str);
	ft_putchar('\n');
	exit(ERROR);
}

int				check_nbr_of_param(t_instru *instru, char *str, int line)
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
		print_erro_param(str, line, 2);
	return (0);
}

void			type_p_error(t_param *param, int line, t_instru *ins, int p_in)
{
	ft_putstr("bad parameter at line: ");
	ft_putnbr(line);
	ft_putstr(" for instruction ");
	ft_putstr(ins->opcode);
	ft_putstr(".\nGot ");
	if (param->type == 1)
		ft_putstr("register");
	if (param->type == 2)
		ft_putstr("direct");
	if (param->type == 4)
		ft_putstr("indirect");
	ft_putstr(" for parameter number ");
	ft_putnbr(p_in);
	ft_putstr("\n");
	exit(ERROR);
}

int				check_type_of_param(t_instru *instru, char *str, int line)
{
	extern t_op	g_op_tab[17];
	t_param		*last;
	int			i;
	int			para_index;
	int			checker;

	i = find_op_index(instru->opcode);
	para_index = 1;
	last = instru->param;
	while (last)
	{
		if (para_index == 1)
			checker = g_op_tab[i].type_of_param.param1;
		if (para_index == 2)
			checker = g_op_tab[i].type_of_param.param2;
		if (para_index == 3)
			checker = g_op_tab[i].type_of_param.param3;
		if (checker == 1 || checker == 2 || checker == 4)
		{
			if (last->type != checker)
				type_p_error(last, line, instru, para_index);
		}
		else
		{
			if (last->type > checker)
				type_p_error(last, line, instru, para_index);
		}
		para_index++;
		last = last->next;
	}
	(void)str;
	return (0);
}

void			check_params_error(t_asm *asmbly, char *str, int line)
{
	t_instru	*current;

	if (!(current = find_instru(asmbly, line)))
		current = get_last_instru(asmbly);
	check_nbr_of_param(current, str, line);
	check_type_of_param(current, str, line);
}
