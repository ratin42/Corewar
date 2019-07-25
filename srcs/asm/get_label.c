/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 23:58:26 by ratin             #+#    #+#             */
/*   Updated: 2019/07/26 01:47:25 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/* void	count()
{
	t_instru	*count;
	int	size;

	count = instru->next;
	size = 0;
	while (count)
	{
		if (count->label )
		size += count->byte_size;
		count = count->next;
	}
}
 */

int		compare_label(char *label1, char *label2)
{
	int			i;

	i = 0;
	while (label1[i] != LABEL_CHAR)
		i++;
	i++;
	if (ft_strcmp(label1, label2) == 0)
		return (1);
	return (0);
}

/* void	fill_label(t_asm *asmbly, t_instru *instru, int size)
{
	int			i;

	i = 0;
	while (instru->conv_par[i] && instru->conv_par[i] != 'L')
		i++;
	
} */

void	size_label(t_asm *asmbly, t_instru *instru, char *label)
{
	t_instru	*count;
	int			size;
	int			i;

	i = 0;
	count = instru;
	size = 0;
	while (count)
	{
		if (count->label != NULL)
		{
			if (compare_label(count->label, label) == 1)
				break ;
		}
		size += count->byte_size;
		count = count->next;
	}
	size -= 1;
	printf("size = %d for %s\n", size, instru->opcode);
//	fill_label(asmbly, instru, size);
	(void)asmbly;
}

void	get_label_value(t_asm *asmbly, t_instru *instru)
{
	t_param		*param;
	int			i;
	int			count;

	count = 0;
	param = instru->param;
	i = 0;
	while (instru->conv_par[i] && instru->conv_par[i] != 'L')
	{
		if (instru->conv_par[i] == ';')
			count++;
		i++;
	}
	while (count)
	{
		count--;
		param = param->next;
	}
	i = 0;
	while (param->param[i] != LABEL_CHAR)
		i++;
	i++;
	size_label(asmbly, instru, &param->param[i]);
}

void	replace_label(t_asm *asmbly)
{
	t_instru	*instru;

	instru = asmbly->instru;
	while (instru)
	{
		if (ft_strchr(instru->conv_par, 'L') != NULL)
			get_label_value(asmbly, instru);
		instru = instru->next;
	}
}