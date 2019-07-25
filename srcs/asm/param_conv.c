/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:17:06 by ratin             #+#    #+#             */
/*   Updated: 2019/07/25 04:07:06 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*reg_conver(t_param *param)
{
	char		*result;
	char		*tmp;

	if (ft_strlen(param->param) == 2)
	{
		if (!(result = (char *)malloc(sizeof(char) * 3)))
			exit(ERROR);
		result[0] = '0';
		result[1] = param->param[1];
		result[2] = '\0';
	}
	else
		result = ft_convert_base_finale(&param->param[1], "0123456789abcdef");
	if (ft_strlen(result) < 2)
	{
		if (!(tmp = ft_strdup(result)))
			exit(ERROR);
		free(result);
		if (!(result = (char *)malloc(sizeof(char) * 3)))
			exit(ERROR);
		result[0] = '0';
		result[1] = tmp[0];
		result[2] = '\0';
		free(tmp);
	}
	return (result);
}

static char		*lab_conver(int size)
{
	char		*conv;
	int			i;

	i = 0;
	if (!(conv = (char *)ft_memalloc(sizeof(char) * size + 1)))
		exit(ERROR);
	while (size - i)
	{
		conv[i] = 'L';
		i++;
	}
	conv[i] = '\0';
	return (conv);
}

static char		*fill_direct(int size, char **conv)
{
	char		*tmp;
	int			i;

	i = 0;
	if (!(tmp = ft_strdup(*conv)))
		exit(ERROR);
	free(*conv);
	if (!(*conv = (char *)malloc(sizeof(char)
		* (size + (int)ft_strlen(tmp) + 1))))
		exit(ERROR);
	while (size - i)
	{
		(*conv)[i] = '0';
		i++;
	}
	(*conv)[i] = '\0';
	ft_strcat(*conv, tmp);
	free(tmp);
	return (*conv);
}

static char		*reduce_conv(int size, char **conv)
{
	char		*tmp;
	int			i;
	int			new_size;
	int			tmp_size;

	i = 0;
	if (!(tmp = ft_strdup(*conv)))
		exit(ERROR);
	tmp_size = ft_strlen(tmp) - 1;
	new_size = size + (int)ft_strlen(tmp) - 1;
	free(*conv);
	if (!(*conv = (char *)malloc(sizeof(char)
		* (size + (int)ft_strlen(tmp) + 1))))
		exit(ERROR);
	(*conv)[new_size + 1] = '\0';
	while (new_size >= 0)
	{
		(*conv)[new_size] = tmp[tmp_size];
		new_size--;
		tmp_size--;
	}
	free(tmp);
	return (*conv);
}

char		*dir_conver(t_param *param, t_instru *instru)
{
	extern t_op	g_op_tab[17];
	char		*conv;
	int			size;
	int			op_index;
	int			i;

	i = 0;
	conv = NULL;
	op_index = find_op_index(instru->opcode);
	if (g_op_tab[op_index].direct_size == 1)
		size = 4;
	else
		size = 8;
	if (ft_strchr(param->param, ':') != NULL)
		return (lab_conver(size));
	conv = ft_convert_base_finale(&param->param[1], "0123456789abcdef");
	size -= ft_strlen(conv);
	if (size > 0)
		conv = fill_direct(size, &conv);
	else if (size < 0)
		conv = reduce_conv(size, &conv);
	return (conv);
}
