/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:43:44 by ratin             #+#    #+#             */
/*   Updated: 2019/07/23 22:09:23 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				get_nbr_of_params(char *opcode)
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

int				get_comma(char *str, int i)
{
	int			y;

	y = 0;
	while (str[i + y] != ',' && str[i + y]
		&& (str[i + y] < 9 || str[i + y] > 13))
	{
		if (str[i + y] == COMMENT_CHAR)
			return (-1);
		y++;
	}
	return (y);
}

void			fill_params(t_asm *asmbly, char *str, int line)
{
	t_instru	*instru;
	int			param_nbr;
	int			i;
	int			y;
	char		*param;

	i = 0;
	param_nbr = 0;
	instru = find_instru(asmbly, line);
	while (str[i])
	{
		y = 0;
		i++;
		while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		if ((y = get_comma(str, i)) == -1)
			return ;
		param = ft_strsub(str, i, y);
		add_param(instru, line, param);
		free(param);
		i += y + 1;
		param_nbr++;
	}
}

void			get_params(t_asm *asmbly, char *str, int line)
{
	t_instru	*instru;
	int			i;

	i = 0;
	instru = find_instru(asmbly, line);
	instru->nbr_of_params = get_nbr_of_params(instru->opcode);
	while ((str[i] != 32 && (str[i] < 9 || str[i] > 13)) && str[i])
		i++;
	fill_params(asmbly, &str[i], line);
	get_params_type(asmbly, &str[i], line);
}
