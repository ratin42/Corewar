/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:47:52 by ratin             #+#    #+#             */
/*   Updated: 2019/08/09 13:52:07 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_prog(t_asm *asmbly)
{
	asmbly->name = NULL;
	asmbly->comment = NULL;
	asmbly->instru = NULL;
}

void		print_writing(char *str)
{
	int		i;

	i = 0;
	ft_putstr("Writing output program to ");
	while (str[i] && str[i] == '.')
		i++;
	while (str[i])
	{
		ft_putchar(str[i]);
		if (str[i] == '.')
			break ;
		i++;
	}
	ft_putstr("cor\n");
}

/* void end (void) __attribute__((destructor))
{
	while(1);
} */

int			main(int ac, char **av)
{
	t_asm	asmbly;

	if (ac < 2)
	{
		ft_putstr_fd("Usage: ./asm <sourcefile.s>\n", 2);
		exit(ERROR);
	}
	init_prog(&asmbly);
	parse_file(&asmbly, av[ac - 1]);
	dlt_lst_empty_lbl(&asmbly);
	convert_instruction(&asmbly);
	count_size(&asmbly);
	write_file(&asmbly, av[ac - 1]);
	print_writing(av[ac -1]);
	free_prog(&asmbly);
	//print_instruction(&asmbly);
	return (0);
}

//TODO
//Mauvais caractères dans un label 
//taille du label du name et comment
//Référence à un label inexistant depuis un direct ou un indirect 
//checker la presence d'au moins une instruction
