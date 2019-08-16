/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 12:21:54 by ratin             #+#    #+#             */
/*   Updated: 2019/08/16 15:21:32 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

void	ft_get_opcode(t_corewar *cor, t_arg *arg)
{
	unsigned char	bmask;

	bmask = 3;
	printf("have ocp\n");
	arg->type[0] = ((bmask << 6) & cor->code[cor->pc]) >> 6;
	arg->type[1] = ((bmask << 4) & cor->code[cor->pc]) >> 4;
	arg->type[2] = ((bmask << 2) & cor->code[cor->pc]) >> 2;
	arg->type[3] = bmask & cor->code[cor->pc];
	cor->pc++;
}

void			init_arg(t_arg *arg, int opcode)
{
	extern t_op	g_op_tab[17];
	
	arg->nb_arg = g_op_tab[opcode - 1].nbr_of_param;
	if (g_op_tab[opcode - 1].direct_size == 1)
		arg->dir_size = 2;
	else
		arg->dir_size = 4;
	if (g_op_tab[opcode - 1].coding_opcode == 1)
		arg->ocp = 1;
	else
		arg->ocp = 0;
}

static inline int		ft_get_arg_size(t_arg_type arg_type, int dir_size)
{
	printf("arg type = %d\n", arg_type);
	if (arg_type == REG_CODE)
		return (1);
	if (arg_type == IND_CODE)
		return (IND_SIZE);
	if (arg_type == DIR_CODE)
	{
		return (dir_size);
	}
	return (0);
}

void	ft_get_args_size(t_arg *arg)
{
	int		i;
	
	i = 0;
	if (arg->ocp == 1)
	{
		while (i < arg->nb_arg)
		{
			printf("passage\n");
			arg->size[i] = ft_get_arg_size(arg->type[i], arg->dir_size);
			i++;
		}
	}
	else
		arg->size[0] = 4;
}

void		get_params(t_corewar *cor, t_arg *arg, int opcode)
{
	printf("pour %d-----pc = %d---------------------\n", opcode, cor->pc);
	ft_bzero(arg, sizeof(arg));
	init_arg(arg, opcode);
	printf("il y a %d argument\n", arg->nb_arg);
	if (arg->ocp == 1)
		ft_get_opcode(cor, arg);
	ft_get_args_size(arg);
	printf("size p1 = %d p2 = %d p3 = %d\n", arg->size[0], arg->size[1]
		, arg->size[2]);
	pcode(cor, cor->pc);
	ft_get_args(cor, arg);
}
