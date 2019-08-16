/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_ld.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:49:30 by ratin             #+#    #+#             */
/*   Updated: 2019/08/15 22:53:15 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompile.h"

void	inst_ld(t_corewar *cor)
{
	char	*param1;
	char	*param2;
	int		*type_param;
	
	type_param = check_opcode(cor);
	param1 = get_small_param(cor, type_param[0]);
	param2 = get_small_param(cor, type_param[1]);
	if ((type_param[0] != DIR_CODE && type_param[0] == IND_CODE)
		|| type_param[1] != REG_CODE)
		decomp_quit("Bad parameter for ld\n");
	write(cor->fd, "ld ", 4);
	write(cor->fd, param1, ft_strlen(param1));
	write(cor->fd, ", ", 2);
	write(cor->fd, param2, ft_strlen(param2));
	write(cor->fd, "\n", 1);
	free(param1);
	free(param2);
	free(type_param);
}
