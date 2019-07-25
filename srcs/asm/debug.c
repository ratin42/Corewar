/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:16:31 by ratin             #+#    #+#             */
/*   Updated: 2019/07/26 00:30:01 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_bytecode(char *str)
{
	int			i;
	int			y;

	i = 0;
	y = 0;
	while (str[i])
	{
/* 		if (y % 2 == 0)
			ft_putchar(' '); */
		ft_putchar(str[i]);
		i++;
		y++;
	}
	printf("\n");
}

void			print_param(t_instru *instru)
{
	t_param		*last;

	last = instru->param;
	while (last)
	{
		printf("	param = %-10s type = %d\n", last->param, last->type);
		last = last->next;
	}
}

void			print_instruction(t_asm *asmbly)
{
	t_instru	*instru;

	instru = asmbly->instru;
	printf("\n~~~ instruction are ~~~\n");
	while (instru)
	{
		printf("___________________________________\n");
		printf("\nopcode = %s\n", instru->opcode);
		printf("line = %d\n", instru->line);
		printf("label = %s\n", instru->label);
		printf("nbr_of_param = %d\n", instru->nbr_of_params);
		print_param(instru);
		printf("     =>");
		fflush(stdout);
		print_bytecode(instru->conv_par);
		printf("size => ");
		fflush(stdout);
		ft_putnbr(instru->byte_size);
		printf("\n");
		instru = instru->next;
	}
	printf("___________________________________\n");
	printf("\n~~~       FIN       ~~~\n");
}
