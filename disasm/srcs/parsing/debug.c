/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:18:53 by ratin             #+#    #+#             */
/*   Updated: 2019/08/29 14:52:43 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

void	print_champion(t_corewar *cor)
{
	unsigned int i;

	i = 0;
	printf("champion name = %s\n", cor->name);
	printf("champion size = %u\n", cor->size);
	printf("champion comment = %s\n", cor->comment);
	printf("champion magic = %u\n", cor->magic);
	while (i < cor->size)
	{
		printf("%02x ", cor->code[i]);
		i++;
	}
	printf("\n");
}

void	pcode(t_corewar *cor, int pc)
{
	printf("code = |%02x|\n", cor->code[pc]);
}
