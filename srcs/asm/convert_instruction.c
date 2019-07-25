/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:01:04 by ratin             #+#    #+#             */
/*   Updated: 2019/07/25 04:42:30 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		*convert_params(t_asm *asmbly, t_instru *instru)
{
	t_param		*param;
	char		*result;

	result = NULL;
	param = instru->param;
	while (param)
	{
		if (param->type == 1)
			result = ft_strjoin_free(result, reg_conver(param), 1);
		if (param->type == 2)
			result = ft_strjoin_free(result, dir_conver(param, instru), 1);
		if (param->type == 4)
			result = ft_strjoin_free(result, ind_conver(param, instru), 1);
		param = param->next;
	}
	(void)asmbly;
	return (result);
}

void			convert_instruction(t_asm *asmbly)
{
	t_instru	*instru;

	instru = asmbly->instru;
	while (instru)
	{
		printf("\npour instruction %s --------------------\n", instru->opcode);
		instru->converted_params = convert_params(asmbly, instru);
		print_bytecode(instru->converted_params);
		instru = instru->next;
	}
}
