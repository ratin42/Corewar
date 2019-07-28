/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:35:31 by ratin             #+#    #+#             */
/*   Updated: 2019/07/28 18:25:29 by ratin            ###   ########.fr       */
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

int				check_opc_presence(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != ':')
		i++;
	while (str[++i])
	{
		if (str[i] && str[i] != 32 && (str[i] < 9 || str[i] > 13))
			return (1);
	}
	return (0);
}

int				get_label(t_asm *asmbly, char *str, int line)
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
	{
		if ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
			return (0);
		i++;
	}
	if (!(label = ft_strsub(str, y, i)))
		exit(ERROR);
	verify_label(label, line);
	instru->label = label;
	if (check_opc_presence(str) == 0)
		return (-1);
	return (0);
}

static int		last_instru_cmplt(t_asm *asmbly)
{
	t_instru	*last;

	last = asmbly->instru;
	if (last == NULL)
		return (1);
	while (last->next)
		last = last->next;
	if (last->opcode == NULL)
		return (0);
	return (1);
}

void			get_instruction(t_asm *asmbly, char *str, int line)
{
	int			indexer;
	t_instru	*instru;

	indexer = 0;
	if (last_instru_cmplt(asmbly) == 1)
		add_instru(asmbly, line);
	if (ft_strchr(str, LABEL_CHAR) != NULL)
	{
		if (get_label(asmbly, str, line) == -1)
		{
			instru = find_instru(asmbly, line);
			instru->line++;
			return ;
		}
	}
	indexer = get_opcode(asmbly, str, line);
	get_params(asmbly, &str[indexer], line);
	check_params_error(asmbly, str, line);
}
