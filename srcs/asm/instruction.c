/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:50:07 by ratin             #+#    #+#             */
/*   Updated: 2019/07/21 00:10:41 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_instru		*find_instru(t_asm *asmbly, int line)
{
	t_instru	*last;

	last = asmbly->instru;
	while (last)
	{
		if (last->line == line)
			return (last);
		last = last->next;
	}
	return (NULL);
}

t_instru		*create_instuction(int line)
{
	t_instru	*new_instru;

	if (!(new_instru = malloc(sizeof(*new_instru))))
		exit(ERROR);
	new_instru->param = NULL;
	new_instru->label = NULL;
	new_instru->opcode = 0;
	new_instru->line = line;
	new_instru->next = NULL;
	return (new_instru);
}

void			add_instru(t_asm *asmbly, int line)
{
	t_instru	*new_instru;
	t_instru	*last;

	last = asmbly->instru;
	new_instru = create_instuction(line);
	if (asmbly->instru == NULL)
		asmbly->instru = new_instru;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_instru;
	}
}
