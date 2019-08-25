/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:17:06 by ratin             #+#    #+#             */
/*   Updated: 2019/08/25 01:52:58 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		*lab_conver(t_asm *asmbly, int size)
{
	char		*conv;
	int			i;

	i = 0;
	if (!(conv = (char *)ft_memalloc(sizeof(char) * size + 1)))
		quit_prog(asmbly);
	while (size - i)
	{
		conv[i] = 'L';
		i++;
	}
	conv[i] = '\0';
	return (conv);
}

char			*fill_direct(t_asm *asmbly, int size, char **conv)
{
	char		*tmp;
	int			i;

	i = 0;
	if (!(tmp = ft_strdup(*conv)))
		quit_prog(asmbly);
	free(*conv);
	if (!(*conv = (char *)ft_memalloc(sizeof(char)
		* (size + (int)ft_strlen(tmp) + 1))))
		quit_prog(asmbly);
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

char			*reduce_conv(t_asm *asmbly, int size, char **conv)
{
	char		*tmp;
	int			i;
	int			new_size;
	int			tmp_size;

	i = 0;
	if (!(tmp = ft_strdup(*conv)))
		quit_prog(asmbly);
	tmp_size = ft_strlen(tmp) - 1;
	new_size = size + (int)ft_strlen(tmp) - 1;
	free(*conv);
	if (!(*conv = (char *)ft_memalloc(sizeof(char)
		* (size + (int)ft_strlen(tmp) + 1))))
		quit_prog(asmbly);
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

static char		*get_conv(char *cpy)
{
	char		*conv;

	//printf("cpy = %s atoll cpy = %lld\n", cpy, ft_atoll(cpy));
/* 	if (cpy[0] == '-' && ((ft_strlen(cpy) > 10 && ft_atoll(cpy) < -2147483648)
		|| ft_strlen(cpy) > 11))
		conv = ft_ul_convert_base("-2147483648", "0123456789abcdef");
	else if ((ft_strlen(cpy) > 10 && ft_atoll(cpy) > 2147483647)
		|| ft_strlen(cpy) > 11)
		conv = ft_ul_convert_base("2147483647", "0123456789abcdef");
	else */
		conv = ft_ul_convert_base(cpy, "0123456789abcdef");
	return (conv);
}

char			*dir_conver(t_asm *asmbly, t_param *param, t_instru *instru)
{
	extern t_op	g_op_tab[17];
	char		*conv;
	char		*cpy;
	int			size;
	int			op_index;

	conv = NULL;
	op_index = find_op_index(instru->opcode);
	if (g_op_tab[op_index].direct_size == 1)
		size = 4;
	else
		size = 8;
	if (ft_strchr(param->param, ':') != NULL)
		return (lab_conver(asmbly, size));
	if (!(cpy = ft_strdup(&param->param[1])))
		quit_prog(asmbly);
	conv = get_conv(cpy);
	free(cpy);
	size -= ft_strlen(conv);
	if (size > 0)
		conv = fill_direct(asmbly, size, &conv);
	else if (size < 0)
		conv = reduce_conv(asmbly, size, &conv);
	return (conv);
}

char			*ind_conver(t_asm *asmbly, t_param *param, t_instru *instru)
{
	char		*conv;
	int			size;
	int			i;

	i = 0;
	conv = NULL;
	size = 4;
	if (ft_strchr(param->param, ':') != NULL)
		return (lab_conver(asmbly, size));
	conv = ft_ul_convert_base(param->param, "0123456789abcdef");
	size -= ft_strlen(conv);
	if (size > 0)
		conv = fill_direct(asmbly, size, &conv);
	else if (size < 0)
		conv = reduce_conv(asmbly, size, &conv);
	(void)instru;
	return (conv);
}
