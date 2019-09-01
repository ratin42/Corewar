/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:41:23 by ratin             #+#    #+#             */
/*   Updated: 2019/09/01 20:16:57 by ratin            ###   ########.fr       */
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

static char		*get_good_value(char **param, int type)
{
	char		*result;

	if (type == DIR_CODE)
		result = ft_litoa((int)ft_atoll(&(*param)[1]));
	else
		result = ft_litoa((int)ft_atoll((*param)));
	free(*param);
	return (result);
}

static int		check_ind(char **param)
{
	int			i;

	i = 0;
	if ((*param)[i] == ':')
		return (check_label((*param)));
	while ((*param)[i])
	{
		if (((*param)[i] == '-' || (*param)[i] == '+')
			&& ((*param)[i + 1]) && ft_isdigit((*param)[i + 1]))
			i++;
		if (ft_isdigit((*param)[i]) == 0)
			return (0);
		i++;
	}
	(*param) = get_good_value((param), IND_CODE);
	return (1);
}

static int		check_dir(char **param)
{
	int			i;

	i = 0;
	if ((*param)[i] == '%')
		i++;
	else
		return (0);
	if ((*param)[i] == '\0')
		return (0);
	if ((*param)[i] == ':')
		return (check_label(&(*param)[i]));
	while ((*param)[i])
	{
		if (((*param)[i] == '-' || (*param)[i] == '+')
			&& ((*param)[i + 1]) && ft_isdigit((*param)[i + 1]))
			i++;
		if (ft_isdigit((*param)[i]) == 0)
			return (0);
		i++;
	}
	*param = get_good_value(param, DIR_CODE);
	*param = ft_strjoin_free("%", *param, 2);
	return (1);
}

void			get_params_type(t_asm *asmbly, char *str, int line)
{
	t_instru	*instru;
	t_param		*param;

	if (!(instru = find_instru(asmbly, line)))
		instru = get_last_instru(asmbly);
	param = instru->param;
	while (param)
	{
		if (is_register(param->param) == T_REG)
			param->type = T_REG;
		else if (check_dir(&param->param) == 1)
			param->type = T_DIR;
		else if (check_ind(&param->param) == 1)
			param->type = T_IND;
		else
			error_type(asmbly, param);
		param = param->next;
	}
	(void)str;
}
