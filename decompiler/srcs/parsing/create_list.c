/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:07:03 by ratin             #+#    #+#             */
/*   Updated: 2019/08/15 21:52:23 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompile.h"

void (*g_func[17])(t_corewar *cor) =
{
	inst_live,
	NULL,//inst_ld,
	NULL,//inst_st,
	NULL,//inst_add,
	NULL,//inst_sub,
	inst_and,
	NULL,//inst_or,
	NULL,//inst_xor,
	inst_zjmp,
	NULL,//inst_ldi,
	inst_sti,
	NULL,//inst_fork,
	NULL,//inst_lld,
	NULL,//inst_lldi,
	NULL,//inst_lfork,
	NULL,//inst_aff
};

void	create_list(t_corewar *cor)
{
	int	opcode;

	while (cor->pc < cor->size)
	{
		opcode = cor->code[cor->pc++];
		g_func[opcode - 1](cor);
	}
}
