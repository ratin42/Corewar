/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_zjmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 21:52:53 by ratin             #+#    #+#             */
/*   Updated: 2019/08/16 14:14:06 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

void	inst_zjmp(t_corewar *cor)
{
	char	*param1;

	param1 = get_small_dir(cor);
	write(cor->fd, "zjmp ", 5);
	write(cor->fd, param1, ft_strlen(param1));
	write(cor->fd, "\n", 1);
	free(param1);
}
