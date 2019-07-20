/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:16:00 by ratin             #+#    #+#             */
/*   Updated: 2019/07/20 22:16:10 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_opcode(t_asm *asmbly, char *str, int line)
{
	int		i;
	int		y;
	char	*opcode;
	t_instru	*instru;

	i = 0;
	y = 0;
	instru = find_instru(asmbly, line);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i + y] && str[i + y] != ' ')
		y++;
	if (!(opcode = ft_strsub(str, i, y)))
		exit(ERROR);
	instru->opcode = opcode;
	(void)asmbly;
	(void)line;
}