/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_conv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 04:38:57 by ratin             #+#    #+#             */
/*   Updated: 2019/07/25 04:47:25 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char		*reg_conver(t_param *param)
{
	char		*result;
	char		*tmp;

	result = ft_convert_base_finale(&param->param[1], "0123456789abcdef");
	if (ft_strlen(result) < 2)
	{
		if (!(tmp = ft_strdup(result)))
			exit(ERROR);
		free(result);
		if (!(result = (char *)malloc(sizeof(char) * 3)))
			exit(ERROR);
		result[0] = '0';
		result[1] = tmp[0];
		result[2] = '\0';
		free(tmp);
	}
	return (result);
}
