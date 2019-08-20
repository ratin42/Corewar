/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 22:54:44 by ratin             #+#    #+#             */
/*   Updated: 2019/08/20 23:16:45 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char			*get_result(t_asm *asmbly, t_param *param, t_instru **instru
	, char **result)
{
	if (param->type == 1)
	{
		if (!((*result) = ft_strjoin_free((*result), reg_conver(asmbly
			, param), 3)))
			quit_prog(asmbly);
	}
	if (param->type == 2)
	{
		if (!((*result) = ft_strjoin_free((*result), dir_conver(asmbly, param
			, *instru), 3)))
			quit_prog(asmbly);
	}
	if (param->type == 4)
	{
		if (!((*result) = ft_strjoin_free((*result), ind_conver(asmbly, param
			, *instru), 3)))
			quit_prog(asmbly);
	}
	if (!((*result) = ft_strjoin_free((*result), ";", 1)))
		quit_prog(asmbly);
	return (*result);
}

char			*convert_params(t_asm *asmbly, t_instru **instru)
{
	t_param		*param;
	char		*result;

	if (!(result = (char *)ft_memalloc(sizeof(char))))
		quit_prog(asmbly);
	param = (*instru)->param;
	while (param)
	{
		result = get_result(asmbly, param, instru, &result);
		param = param->next;
	}
	return (result);
}