/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:16:31 by ratin             #+#    #+#             */
/*   Updated: 2019/07/23 21:47:05 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
		printf("line = %d\n", instru->line);
		printf("label = %s\n", instru->label);
		printf("opcode = %s\n", instru->opcode);
		printf("nbr_of_param = %d\n", instru->nbr_of_params);
		print_param(instru);
		instru = instru->next;
		printf("___________________________________\n");
	}
	printf("\n~~~       FIN       ~~~\n");
}
