/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plst_manipulators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:31:40 by gly               #+#    #+#             */
/*   Updated: 2019/08/09 14:12:10 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"

t_plst	*ft_plst_init(t_corewar *cor)
{
	int			i;
	t_plst		*plst;
	t_plst		*elem;

	i = 0;
	while (i < cor->nb_players)
	{
		if (!(elem = malloc(sizeof(t_plst))))
			return (NULL);
		ft_memcpy(&(elem->p), cor->process + i, sizeof(t_process));
		elem->next = plst;
		plst = elem;
		i++;
	}
	return (plst);
}
