/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opcode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 21:16:00 by ratin             #+#    #+#             */
/*   Updated: 2019/07/30 22:31:41 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			check_opcode(char *opcode, int line, char *str, int i_opcode)
{
	extern t_op	g_op_tab[17];
	int			i;

	i = 0;
	while (g_op_tab[i].name != NULL)
	{
		if (ft_strcmp(opcode, g_op_tab[i].name) == 0)
			return ;
		i++;
	}
	ft_putstr("Lexical error for opcode at line ");
	ft_putnbr(line);
	ft_putstr(" ->");
	ft_putstr(&str[i_opcode]);
	ft_putchar('\n');
	exit(ERROR);
}

int				pass_label_char(char *str)
{
	int			i;

	i = 0;
	if (ft_strchr(str, LABEL_CHAR) != NULL)
	{
		while (str[i] && str[i] != LABEL_CHAR)
		{
			if ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
			{
				i = 0;
				break ;
			}
			i++;
		}
	}
	return (i);
}

int				get_opcode(t_asm *asmbly, char *str, int line)
{
	int			i;
	int			y;
	char		*opcode;
	t_instru	*instru;

	i = 0;
	y = 0;
	instru = find_instru(asmbly, line);
	i = pass_label_char(str);
	if (str[i] == ':')
		i++;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i + y] && str[i + y] != 32
		&& (str[i + y] < 9 || str[i + y] > 13))
		y++;
	if (!(opcode = ft_strsub(str, i, y)))
		exit(ERROR);
	//printf("str = %s line = %d\n", str, line);
	check_opcode(opcode, line, str, i);
	instru->opcode = opcode;
	return (i);
}
