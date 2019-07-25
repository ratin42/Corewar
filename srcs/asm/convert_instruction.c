/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:01:04 by ratin             #+#    #+#             */
/*   Updated: 2019/07/25 20:32:56 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		*convert_params(t_instru *instru)
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
	return (result);
}

static char		*convert_opcode(t_instru *instru)
{
	extern t_op	g_op_tab[17];
	char		*conv;
	char		*c_opcode;
	int			op_index;
	int			size;

	size = 2;
	op_index = find_op_index(instru->opcode);
	c_opcode = ft_itoa(g_op_tab[op_index].opcode);
	conv = ft_convert_base_finale(c_opcode, "0123456789abcdef");
	size -= ft_strlen(conv);
	if (size > 0)
		conv = fill_direct(size, &conv);
	else if (size < 0)
		conv = reduce_conv(size, &conv);
	free(c_opcode);
	return (conv);
}

void			convert_instruction(t_asm *asmbly)
{
	extern t_op	g_op_tab[17];
	t_instru	*instru;
	int			op_index;

	instru = asmbly->instru;
	while (instru)
	{
		op_index = find_op_index(instru->opcode);
		//printf("\n--------instruction %s-------\n", instru->opcode);
		instru->converted_params = convert_opcode(instru);
		if (g_op_tab[op_index].coding_opcode == 1)
		{
			instru->converted_params = ft_strjoin_free(instru->converted_params
				, get_opc(instru), 1);
		}
		instru->converted_params = ft_strjoin_free(instru->converted_params
			, convert_params(instru), 1);
		//printf("\n--------instruction %s-------\n", instru->converted_params);
		instru = instru->next;
	}
}
