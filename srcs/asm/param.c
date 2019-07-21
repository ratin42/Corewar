/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:43:44 by ratin             #+#    #+#             */
/*   Updated: 2019/07/21 23:56:57 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_param			*create_param(int line, char *param)
{
	t_param		*new_param;

	if (!(new_param = malloc(sizeof(*new_param))))
		exit(ERROR);
	new_param->value = 0;
	new_param->line = line;
	new_param->param = ft_strdup(param);
	new_param->next = NULL;
	return (new_param);
}

void			add_param(t_instru *instru, int line, char *param)
{
	t_param		*new_param;
	t_param		*last;

	last = instru->param;
	new_param = create_param(line, param);
	if (instru->param == NULL)
		instru->param = new_param;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_param;
	}
}

int				get_nbr_of_params(char *opcode)
{
	extern t_op	g_op_tab[17];
	int			i;

	i = 0;
	if (ft_strcmp(opcode, "(null)") == 0)
		return (0);
	while (g_op_tab[i].name != NULL)
	{
		if (ft_strcmp(opcode, g_op_tab[i].name) == 0)
			break ;
		i++;
	}
	return (g_op_tab[i].nbr_of_param);
}

void			get_params(t_asm *asmbly, char *str, int line)
{
	t_instru	*instru;
	int			i;

	i = 0;
	instru = find_instru(asmbly, line);
	instru->nbr_of_params = get_nbr_of_params(instru->opcode);
	while (str[i] && str[i] != ' ')
		i++;
	fill_params(asmbly, &str[i], line);
}
