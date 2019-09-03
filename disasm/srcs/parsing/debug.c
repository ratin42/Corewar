/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:18:53 by ratin             #+#    #+#             */
/*   Updated: 2019/09/03 13:23:37 by hlombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

//on rend ce .c ?

void	print_champion(t_corewar *cor)
{
	unsigned int i;

	i = 0;
	ft_printf("champion name = %s\n", cor->name);
	ft_printf("champion size = %u\n", cor->size);
	ft_printf("champion comment = %s\n", cor->comment);
	ft_printf("champion magic = %u\n", cor->magic);
	while (i < cor->size)
	{
		ft_printf("%02x ", cor->code[i]);
		i++;
	}
	ft_printf("\n");
}

void	pcode(t_corewar *cor, int pc)
{
	ft_printf("code = |%02x|\n", cor->code[pc]);
}
