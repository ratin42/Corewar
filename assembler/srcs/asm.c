/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:47:52 by ratin             #+#    #+#             */
/*   Updated: 2019/08/27 19:47:50 by ratin            ###   ########.fr       */
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
	char	*new_file;

	i = 0;
	new_file = ft_strndup(str, ft_strlen(str) - 2);
	ft_putstr("Writing output program to .");
	if (str[i] != '/')
		ft_putchar('/');
	ft_putstr(new_file);
	ft_putstr(".cor\n");
	free(new_file);
}

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
	print_writing(av[ac - 1]);
	free_prog(&asmbly);
	return (0);
}

//faire les commentaire sur plusieurs ligne
//protection contre dev/ran null