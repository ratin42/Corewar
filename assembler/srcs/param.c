/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 20:02:59 by ratin             #+#    #+#             */
/*   Updated: 2019/09/05 01:08:13 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_nbr_of_params(char *opcode)
{
	extern t_op	g_op_tab[17];
	int			i;

	i = 0;
	if (ft_strcmp(opcode, "(null)") == 0)
		return (0);
	while (g_op_tab[i].name != NULL)
	{
		if (ft_strcmp(opcode, g_op_tab[i].name) == 0)
			break ;
		i++;
	}
	return (g_op_tab[i].nbr_of_param);
}

int			get_comma(char *str, int i)
{
	int			y;

	y = 0;
	while (str[i + y] && str[i + y] != SEPARATOR_CHAR && str[i + y] != 32
		&& (str[i + y] < 9 || str[i + y] > 13))
	{
		if (str[i + y] == COMMENT_CHAR)
			return (-1);
		y++;
	}
	return (y);
}

int				get_last_param(t_asm *asmbly, char *str, int i, int line)
{
	int			y;
	char		*param;
	t_instru	*instru;

	y = 0;
	if (!(instru = find_instru(asmbly, line)))
		instru = get_last_instru(asmbly);
	while (str[i + y] && str[i + y] != COMMENT_CHAR)
		y++;
	if (!(param = ft_strsub(str, i, y)))
		return (0);
	add_param(asmbly, instru, line, param);
	free(param);
	return (1);
}

void		add_free_param(t_asm *asmbly, t_instru **instru, int line
	, char **param)
{
	add_param(asmbly, *instru, line, *param);
	free(*param);
}

int				fill_params(t_asm *asmbly, t_instru **instru, char *str, int line)
{
	int			i;
	int			y;
	char		*param;

	i = -1;
	while (str[++i])
	{
		y = 0;
		if (!(error_comma(asmbly, str, line, i)))
			return (0);
		while ((str[i] == SEPARATOR_CHAR || str[i] == 32
			|| (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		if (str[i] == '\0' || str[i] == COMMENT_CHAR)
			return (1);
		if ((y = get_comma(str, i)) == -1)
		{
			if (!(get_last_param(asmbly, str, i, line)))
				return (0);
			return (1);
		}
		if (!(param = ft_strsub(str, i, y)))
			return (0);
		add_free_param(asmbly, instru, line, &param);
		i += y;
		if (str[i] == '\0')
			break ;
	}
	return (1);
}
