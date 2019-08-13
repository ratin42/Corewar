/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:18:53 by ratin             #+#    #+#             */
/*   Updated: 2019/08/13 21:42:15 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/decompile.h"

void	print_champion(t_corewar *cor)
{
	printf("champion name = %s\n", cor->name);
	printf("champion size = %u\n", cor->size);
	printf("champion comment = %s\n", cor->comment);
	printf("champion magic = %u\n", cor->magic);
	printf("champion code = %x\n", cor->code[0]);
}