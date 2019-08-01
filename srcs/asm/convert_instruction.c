/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:01:04 by ratin             #+#    #+#             */
/*   Updated: 2019/08/01 20:17:47 by ratin            ###   ########.fr       */
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
		{
			if (!(result = ft_strjoin_free(result, reg_conver(param), 1)))
				exit(ERROR);
		}
		if (param->type == 2)
		{
			if (!(result = ft_strjoin_free(result, dir_conver(param, instru), 1)))
				exit(ERROR);
		}
		if (param->type == 4)
		{
			if (!(result = ft_strjoin_free(result, ind_conver(param, instru), 1)))
				exit(ERROR);
		}
		if (!(result = ft_strjoin_free(result, ";", 1)))
			exit(ERROR);
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
	if (!(conv = ft_ul_convert_base(c_opcode, "0123456789abcdef")))
		exit(ERROR);
	free(c_opcode);
	size -= ft_strlen(conv);
	if (size > 0)
		conv = fill_direct(size, &conv);
	else if (size < 0)
		conv = reduce_conv(size, &conv);
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
	print_instruction(asmbly);
	while (instru)
	{
		if (instru->opcode == NULL)
		{
			instru = instru->next;
			continue ;
		}
		printf("->%s line = %d param = %s\n"
			, instru->opcode, instru->line, instru->param->param);
		op_index = find_op_index(instru->opcode);
		instru->conv_par = convert_opcode(instru);
		if (g_op_tab[op_index].coding_opcode == 1)
		{
			instru->conv_par = ft_strjoin_free(instru->conv_par
				, get_ocp(instru), 1);
		}
		instru->conv_par = ft_strjoin_free(instru->conv_par
			, convert_params(instru), 1);
		instru->byte_size = add_byte_size(instru);
		instru = instru->next;
	}
	while (i < 3)
	{
		replace_label(asmbly);
		i++;
	}
}
