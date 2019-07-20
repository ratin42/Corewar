/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:16:00 by ratin             #+#    #+#             */
/*   Updated: 2019/07/21 01:20:13 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			check_opcode(char *opcode, int line)
{
	extern int	g_op_tab[17];
	int			i;

	i = 0;
	while (i < 17)
	{
		printf("opcode = %s\n", (g_op_tab[i]).name);
		i++;
	}
	(void)opcode;
	(void)line;
}

void			get_opcode(t_asm *asmbly, char *str, int line)
{
	int			i;
	int			y;
	char		*opcode;
	t_instru	*instru;

	i = 0;
	y = 0;
	instru = find_instru(asmbly, line);
	if (ft_strchr(str, LABEL_CHAR) != NULL)
	{
		while (str[i] && str[i - 1] != ':')
			i++;
	}
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i + y] && str[i + y] != ' ')
		y++;
	if (!(opcode = ft_strsub(str, i, y)))
		exit(ERROR);
	check_opcode(opcode, line);
	instru->opcode = opcode;
}