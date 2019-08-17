/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:01:04 by ratin             #+#    #+#             */
/*   Updated: 2019/08/09 11:26:00 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*convert_params(t_asm *asmbly, t_instru **instru)
{
	t_param		*param;
	char		*result;

	if (!(result = (char *)ft_memalloc(sizeof(char))))
		quit_prog(asmbly);
	param = (*instru)->param;
	while (param)
	{
		if (param->type == 1)
		{
			if (!(result = ft_strjoin_free(result, reg_conver(asmbly, param), 3)))
				quit_prog(asmbly);
		}
		if (param->type == 2)
		{
			if (!(result = ft_strjoin_free(result, dir_conver(asmbly, param, *instru), 3)))
				quit_prog(asmbly);
		}
		if (param->type == 4)
		{
			if (!(result = ft_strjoin_free(result, ind_conver(asmbly, param, *instru), 3)))
				quit_prog(asmbly);
		}
		if (!(result = ft_strjoin_free(result, ";", 1)))
				quit_prog(asmbly);
		param = param->next;
	}
	return (result);
	(void)asmbly;
}

static char		*convert_opcode(t_asm *asmbly, t_instru *instru)
{
	extern t_op	g_op_tab[17];
	char		*conv;
	char		*c_opcode;
	int			op_index;
	int			size;

	size = 2;
	op_index = find_op_index(instru->opcode);
	c_opcode = ft_itoa(g_op_tab[op_index].opcode);
	if (!(conv = ft_ul_convert_base(c_opcode, "0123456789abcdef")))
		quit_prog(asmbly);
	free(c_opcode);
	size -= ft_strlen(conv);
	if (size > 0)
		conv = fill_direct(asmbly, size, &conv);
	else if (size < 0)
		conv = reduce_conv(asmbly, size, &conv);
	return (conv);
}

static int		add_byte_size(t_instru *instru)
{
	int			result;
	int			i;

	i = 0;
	result = 0;
	while (instru->conv_par[i])
	{
		if (i % 2 == 0 && instru->conv_par[i] != ';')
			result++;
		i++;
	}
	return (result);
}

void			convert_instruction(t_asm *asmbly)
{
	extern t_op	g_op_tab[17];
	t_instru	*instru;
	int			op_index;
	int			i;

	i = 0;
	instru = asmbly->instru;
	while (instru)
	{
		if (instru->opcode == NULL)
		{
			instru = instru->next;
			continue ;
		}
		op_index = find_op_index(instru->opcode);
		instru->conv_par = convert_opcode(asmbly, instru);
		if (g_op_tab[op_index].coding_opcode == 1)
		{
			instru->conv_par = ft_strjoin_free(instru->conv_par
				, get_ocp(asmbly, instru), 3);
		}
		instru->conv_par = ft_strjoin_free(instru->conv_par
			, convert_params(asmbly, &instru), 3);
		instru->byte_size = add_byte_size(instru);
		instru = instru->next;
	}
	while (i < 3)
	{
		replace_label(asmbly);
		i++;
	}
	print_instruction(asmbly);
}
