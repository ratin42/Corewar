/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:43:44 by ratin             #+#    #+#             */
/*   Updated: 2019/08/27 19:34:51 by ratin            ###   ########.fr       */
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
	while (str[i + y] && str[i + y] != ',' && str[i + y] != 32
		&& (str[i + y] < 9 || str[i + y] > 13))
	{
		if (str[i + y] == COMMENT_CHAR)
			return (-1);
		y++;
	}
	return (y);
}

void		get_last_param(t_asm *asmbly, char *str, int i, int line)
{
	int			y;
	char		*param;
	t_instru	*instru;

	y = 0;
	if (!(instru = find_instru(asmbly, line)))
		instru = get_last_instru(asmbly);
	while (str[i + y] && str[i + y] != '#')
		y++;
	param = ft_strsub(str, i, y);
	add_param(asmbly, instru, line, param);
	free(param);
}

void		error_comma(t_asm *asmbly, char *str, int line, int i)
{
		if (str[i] == ',' && str[i + 1] == ',')
		{
			ft_putstr_fd("Error double comma at line ", 2);
			ft_putnbr_fd(line, 2);
			ft_putchar_fd('\n', 2);
			quit_prog(asmbly);
		}
}

void		fill_params(t_asm *asmbly, t_instru **instru, char *str, int line)
{
	int			i;
	int			y;
	char		*param;

	i = -1;
	while (str[++i])
	{
		y = 0;
		error_comma(asmbly, str, line, i);
		while ((str[i] == ',' || str[i] == 32
			|| (str[i] >= 9 && str[i] <= 13)) && str[i])
			i++;
		if (str[i] == '\0' || str[i] == COMMENT_CHAR)
			return ;
		if ((y = get_comma(str, i)) == -1)
		{
			get_last_param(asmbly, str, i, line);
			return ;
		}
		param = ft_strsub(str, i, y);
		add_param(asmbly, *instru, line, param);
		free(param);
		i += y;
		if (str[i] == '\0')
			break ;
	}
}

void		check_end_coma(t_asm *asmbly, char *str, int line)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			return ;
		i++;
	}
	if (str[ft_strlen(str) - 1] == ',')
	{
		ft_putstr_fd("Syntax error ENDLINE line ", 2);
		ft_putnbr_fd(line, 2);
		ft_putchar_fd('\n', 2);
		quit_prog(asmbly);
	}
}

void		get_params(t_asm *asmbly, char *str, int line)
{
	t_instru	*instru;
	int			i;

	i = 0;
	if (!(instru = find_instru(asmbly, line)))
		instru = get_last_instru(asmbly);
	instru->nbr_of_params = get_nbr_of_params(instru->opcode);
	while ((str[i] != 32 && (str[i] < 9 || str[i] > 13)) && str[i])
		i++;
	check_end_coma(asmbly, str, line);
	fill_params(asmbly, &instru, &str[i], line);
	get_params_type(asmbly, &str[i], line);
}
