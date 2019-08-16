/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 20:10:00 by ratin             #+#    #+#             */
/*   Updated: 2019/08/16 14:14:05 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

char		*get_small_param(t_corewar *cor, int type)
{
	if (type == REG_CODE)
		return (get_reg_index(cor));
	if (type == DIR_CODE)
		return (get_small_dir(cor));
	if (type == IND_CODE)
		return (get_ind(cor));
	return (0);
}

void		inst_sti(t_corewar *cor)
{
	char	*param1;
	char	*param2;
	char	*param3;
	int		*type_param;
	
	type_param = check_opcode(cor);
	param1 = get_small_param(cor, type_param[0]);
	param2 = get_small_param(cor, type_param[1]);
	param3 = get_small_param(cor, type_param[2]);
	if (type_param[0] != REG_CODE || type_param[1] == 0 || (type_param[2]
		!= DIR_CODE && type_param[2] != REG_CODE))
		decomp_quit("Bad parameter for sti\n");
	write(cor->fd, "sti ", 4);
	write(cor->fd, param1, ft_strlen(param1));
	write(cor->fd, ", ", 2);
	write(cor->fd, param2, ft_strlen(param2));
	write(cor->fd, ", ", 2);
	write(cor->fd, param3, ft_strlen(param3));
	write(cor->fd, "\n", 1);
	free(param1);
	free(param2);
	free(param3);
	free(type_param);
}
