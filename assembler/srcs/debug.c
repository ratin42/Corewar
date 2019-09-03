/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:16:31 by ratin             #+#    #+#             */
/*   Updated: 2019/09/03 13:17:21 by hlombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//On rend ce .c ?

void			print_bytecode(char *str)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == ';')
			y--;
		if (y % 2 == 0)
			ft_putchar(' ');
		if (str[i] != ';')
			ft_putchar(str[i]);
		i++;
		y++;
	}
	ft_printf("\n");
}

void			print_param(t_instru *instru)
{
	t_param		*last;

	last = instru->param;
	while (last)
	{
		ft_printf("	param = %-10s type = %d\n", last->param, last->type);
		last = last->next;
	}
}

void			print_instruction(t_asm *asmbly)
{
	t_instru	*instru;

	instru = asmbly->instru;
	ft_printf("\n~~~ instruction are ~~~\n");
	while (instru)
	{
		ft_printf("___________________________________\n");
		ft_printf("\nopcode = %s\n", instru->opcode);
		ft_printf("nbr_opcode = %d\n", instru->nbr_opcode);
		ft_printf("line = %d\n", instru->line);
		ft_printf("label = %s\n", instru->label);
		ft_printf("nbr_of_param = %d\n", instru->nbr_of_params);
		print_param(instru);
		if (instru->conv_par != NULL)
		{
			ft_printf("     =>");
			print_bytecode(instru->conv_par);
		}
		ft_printf("\n");
		instru = instru->next;
	}
	ft_printf("___________________________________\n");
	ft_printf("\n~~~       FIN       ~~~\n");
}
