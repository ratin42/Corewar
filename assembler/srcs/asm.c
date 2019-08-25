/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:47:52 by ratin             #+#    #+#             */
/*   Updated: 2019/08/26 01:00:42 by ratin            ###   ########.fr       */
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

//have to close the file
//separator with nothing after
//double_separatorchar.s