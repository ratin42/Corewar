/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:41:23 by ratin             #+#    #+#             */
/*   Updated: 2019/07/28 20:16:37 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_label(char *param)
{
	int			i;

	i = 1;
	if (param[0] != ':')
		return (0);
	if (param[i] == '\0')
		return (0);
	while (param[i])
	{
		if (ft_strchr(LABEL_CHARS, param[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

static int		check_ind(char *param)
{
	int			i;

	i = 0;
	if (param[i] == ':')
		return (check_label(param));
	while (param[i])
	{
		if ((param[i] == '-' || param[i] == '+')
			&& (param[i + 1]) && ft_isdigit(param[i + 1]))
			i++;
		if (ft_isdigit(param[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int		check_dir(char *param)
{
	int			i;

	i = 0;
	if (param[i] == '%')
		i++;
	else
		return (0);
	if (param[i] == ':')
		return (check_label(&param[i]));
	while (param[i])
	{
		if ((param[i] == '-' || param[i] == '+')
			&& (param[i + 1]) && ft_isdigit(param[i + 1]))
			i++;
		if (ft_isdigit(param[i]) == 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void			error_type(t_param *param)
{
	ft_putstr("Lexical error of type for param at line ");
	ft_putnbr(param->line);
	ft_putstr(" ->");
	ft_putstr(param->param);
	ft_putchar('\n');
	exit(ERROR);
}

void			get_params_type(t_asm *asmbly, char *str, int line)
{
	t_instru	*instru;
	t_param		*param;

	instru = find_instru(asmbly, line);
	param = instru->param;
	while (param)
	{
		if (is_register(param->param) == T_REG)
			param->type = T_REG;
		else if (check_dir(param->param) == 1)
			param->type = T_DIR;
		else if (check_ind(param->param) == 1)
			param->type = T_IND;
		else
			error_type(param);
		param = param->next;
	}
	(void)str;
}
