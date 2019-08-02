/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:47:52 by ratin             #+#    #+#             */
/*   Updated: 2019/08/02 06:00:28 by ratin            ###   ########.fr       */
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

void		init_prog(t_asm *asmbly)
{
	asmbly->name = NULL;
	asmbly->comment = NULL;
	asmbly->instru = NULL;
}

int			main(int ac, char **av)
{
	t_asm	asmbly;

	if (ac < 2)
	{
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
		exit(ERROR);
	}
	init_prog(&asmbly);
	parse_file(&asmbly, av[ac - 1]);
	dlt_lst_empty_lbl(&asmbly);
	convert_instruction(&asmbly);
	count_size(&asmbly);
	write_file(&asmbly, av[ac - 1]);
	ft_putstr("Writing output program\n");
	//print_instruction(&asmbly);
	return (0);
}

//changer le fd des error
//gerer les free
//Mauvais caractères dans un label 
//taille du label du name et comment
// Référence à un label inexistant depuis un direct ou un indirect 
// checker la presence d'au moins une instruction