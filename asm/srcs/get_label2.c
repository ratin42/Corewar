/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 00:21:21 by ratin             #+#    #+#             */
/*   Updated: 2019/08/09 14:06:19 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		write_label(t_instru *instru, char *conv)
{
	int		i;
	int		y;

	i = 0;
	y = 0;
	while (instru->conv_par[i] && instru->conv_par[i] != 'L')
		i++;
	while (conv[y])
	{
		instru->conv_par[i + y] = conv[y];
		y++;
	}
}

void		error_no_label(t_asm *asmbly, t_instru *instru, char *label)
{
	ft_putstr_fd("No label ", 2);
	ft_putstr_fd(label, 2);
	ft_putstr_fd(" found for parameter of instruction ", 2);
	ft_putstr_fd(instru->opcode, 2);
	ft_putstr_fd(" line ", 2);
	ft_putnbr_fd(instru->line, 2);
	ft_putstr_fd("\n", 2);
	quit_prog(asmbly);
}

int			reverse_label(t_asm *asmbly, t_instru *instru, char *label)
{
	t_instru	*count;
	int			distance;
	int			max_dist = 65535;

	count = asmbly->instru;
	distance = 0;
	instru->labelsrc = 1;
	while (count)
	{
		if (count->label != NULL)
		{
			if (compare_label(count->label, label) == 1)
				break ;
		}
		count = count->next;
	}
	if (count == NULL)
		error_no_label(asmbly, instru, label);
	while (count && count->labelsrc == 0)
	{
		distance += count->byte_size;
		count = count->next;
	}
	instru->labelsrc = 0;
	distance = max_dist - distance + 1;
	return (distance);
}