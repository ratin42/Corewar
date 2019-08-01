/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 16:35:31 by ratin             #+#    #+#             */
/*   Updated: 2019/08/01 17:33:10 by ratin            ###   ########.fr       */
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
		if (str[i] == COMMENT_CHAR)
			return (0);
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
	if (!(instru = find_instru(asmbly, line)))
	{
		print_instruction(asmbly);
		ft_putstr_fd("couldn't get instruction in get_label\n", 2);
		printf("line = %d\n\n", line);
	}
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
	if (instru->label == NULL)
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
	if (last->label != NULL && last->opcode == NULL)
		return (-1);
	if (last->opcode == NULL)
		return (0);
	return (1);
}

int				check_label_presence(char *str)
{
	int			i;

	i = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
		i++;
	while (str[i] && (ft_strchr(LABEL_CHARS, str[i]) != NULL
		|| str[i] == LABEL_CHAR))
	{
		if (str[i] == LABEL_CHAR)
			return (1);
		i++;
	}
	return (0);
}

void			get_instruction(t_asm *asmbly, char *str, int line)
{
	int			indexer;
	t_instru	*instru;

	indexer = 0;
	//print_instruction(asmbly);
	if (last_instru_cmplt(asmbly) == 1)
		add_instru(asmbly, line);
	if (check_label_presence(str) == 1)
	{
		if (last_instru_cmplt(asmbly) == -1)
			add_instru(asmbly, line);
		if (get_label(asmbly, str, line) == -1)
		{
			if (!(instru = find_instru(asmbly, line)))
				ft_putstr_fd("couldn't get instruction in get_instru\n", 2);
			instru->line++;
			return ;
		}
	}
	indexer = get_opcode(asmbly, str, line);
	get_params(asmbly, &str[indexer], line);
	check_params_error(asmbly, str, line);
	//printf("line %d -> str = %s\n", line, str);
}
