/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:27:45 by ratin             #+#    #+#             */
/*   Updated: 2019/07/22 20:56:51 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_erro_param(char *str, int line, int error)
{
	if (error == 1)
		ft_putstr("Lexical error for param [");
	else if (error == 2)
		ft_putstr("bad number of parameter at [");
	ft_putnbr(line);
	ft_putchar(':');
	ft_putnbr(0);
	ft_putstr("] ->");
	ft_putstr(str);
	ft_putchar('\n');
	exit(ERROR);
}

int				check_nbr_of_param(t_instru *instru, char *str, int line)
{
	t_param		*last;
	int			i;

	last = instru->param;
	i = 0;
	while (last)
	{
		last = last->next;
		i++;
	}
	if (i != instru->nbr_of_params)
		print_erro_param(str, line, 2);
	return (0);
}

void			check_params_error(t_asm *asmbly, char *str, int line)
{
	t_instru	*current;	

	current = find_instru(asmbly, line);
	print_instruction(asmbly);
	check_nbr_of_param(current, str, line);
	(void)str;
}
