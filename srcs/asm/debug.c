/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:16:31 by ratin             #+#    #+#             */
/*   Updated: 2019/07/20 22:25:32 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
		printf("ocp = %s\n", instru->ocp);
		instru = instru->next;
		printf("___________________________________\n");
	}
	printf("\n~~~       FIN       ~~~\n");
}