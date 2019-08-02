/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:17:06 by ratin             #+#    #+#             */
/*   Updated: 2019/08/02 08:45:16 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

char			*fill_direct(int size, char **conv)
{
	char		*tmp;
	int			i;

	i = 0;
	if (!(tmp = ft_strdup(*conv)))
		exit(ERROR);
	free(*conv);
	if (!(*conv = (char *)ft_memalloc(sizeof(char)
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

char			*reduce_conv(int size, char **conv)
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
	if (!(*conv = (char *)ft_memalloc(sizeof(char)
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

char			*dir_conver(t_param *param, t_instru *instru)
{
	extern t_op	g_op_tab[17];
	char		*conv;
	int			size;
	int			op_index;

	conv = NULL;
	op_index = find_op_index(instru->opcode);
	if (g_op_tab[op_index].direct_size == 1)
		size = 4;
	else
		size = 8;
	if (ft_strchr(param->param, ':') != NULL)
		return (lab_conver(size));
	char *cpy;
	cpy = ft_strdup(&param->param[1]);
	conv = ft_ul_convert_base(cpy, "0123456789abcdef");
	size -= ft_strlen(conv);
	if (size > 0)
		conv = fill_direct(size, &conv);
	else if (size < 0)
		conv = reduce_conv(size, &conv);
	return (conv);
}

char			*ind_conver(t_param *param, t_instru *instru)
{
	char		*conv;
	int			size;
	int			i;

	i = 0;
	conv = NULL;
	size = 4;
	if (ft_strchr(param->param, ':') != NULL)
		return (lab_conver(size));
	conv = ft_ul_convert_base(param->param, "0123456789abcdef");
	size -= ft_strlen(conv);
	if (size > 0)
		conv = fill_direct(size, &conv);
	else if (size < 0)
		conv = reduce_conv(size, &conv);
	(void)instru;
	return (conv);
}
