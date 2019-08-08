/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:23:48 by ratin             #+#    #+#             */
/*   Updated: 2019/08/06 18:07:55 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			quit_prog(t_asm *asmbly)
{
	exit(1);
	(void)asmbly;
}

void			free_param(t_instru *instru)
{
	t_param		*param;
	t_param		*tmp;

	param = instru->param;
	while (param)
	{
		tmp = param->next;
		free(param->param);
		free(param);
		param = tmp;
	}
	instru->param = NULL;
}

void			free_instru(t_asm *asmbly)
{
	t_instru	*instru;
	t_instru	*tmp;

	instru = asmbly->instru;
	while (instru)
	{
		tmp = instru->next;
		free(instru->conv_par);
		free(instru->label);
		free(instru->opcode);
		free_param(instru);
		free(instru);
		instru = tmp;
	}
	asmbly->instru = NULL;
}

void	free_prog(t_asm *asmbly)
{
	free(asmbly->name);
	free(asmbly->comment);
	free_instru(asmbly);
}