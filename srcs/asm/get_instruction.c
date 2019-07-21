/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:35:31 by ratin             #+#    #+#             */
/*   Updated: 2019/07/21 23:58:51 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			verify_label(char *label, int line)
{
	int			i;

	i = 0;
	while (label[i])
	{
		if (!(ft_strchr(LABEL_CHARS, label[i])))
		{
			ft_putstr("Lexical error for label at [");
			ft_putnbr(line);
			ft_putchar(':');
			ft_putnbr(i);
			ft_putstr("] ->");
			ft_putstr(&label[i]);
			ft_putchar('\n');
			exit(ERROR);
		}
		i++;
	}
}

void			get_label(t_asm *asmbly, char *str, int line)
{
	t_instru	*instru;
	char		*label;
	int			i;
	int			y;

	i = 0;
	y = 0;
	instru = find_instru(asmbly, line);
	while ((str[y] == 32 || (str[y] >= 9 && str[y] <= 13)) && str[y])
		y++;
	while (str[i] && str[i] != (char)LABEL_CHAR)
		i++;
	if (str[i - 1] == '%')
		return ;
	if (!(label = ft_strsub(str, y, i)))
		exit(ERROR);
	verify_label(label, line);
	instru->label = label;
}

void			get_instruction(t_asm *asmbly, char *str, int line)
{
	int			indexer;

	indexer = 0;
	add_instru(asmbly, line);
	if (ft_strchr(str, LABEL_CHAR) != NULL)
		get_label(asmbly, str, line);
	indexer = get_opcode(asmbly, str, line);
	get_params(asmbly, &str[indexer], line);
}
