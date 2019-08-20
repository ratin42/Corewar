/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_correc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 08:24:07 by ratin             #+#    #+#             */
/*   Updated: 2019/08/20 23:11:36 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		move_label(t_asm *asmbly, t_instru **instru)
{
	char		*label_cpy;
	t_instru	*last;

	last = asmbly->instru;
	label_cpy = ft_strdup((*instru)->label);
	while (last->next->next)
		last = last->next;
	last->next = NULL;
	delete_instru(instru);
	last->label = label_cpy;
	last->added_label = 1;
}

void		dlt_lst_empty_lbl(t_asm *asmbly)
{
	t_instru	*instru;

	instru = asmbly->instru;
	while (instru->next)
		instru = instru->next;
	if (instru->opcode == NULL && instru->label != NULL)
		move_label(asmbly, &instru);
}
