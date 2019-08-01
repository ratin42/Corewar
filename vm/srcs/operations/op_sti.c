/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:18:06 by qtran             #+#    #+#             */
/*   Updated: 2019/08/01 14:18:07 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** Instruction: sti r2, %4, %5
** Copy REG_SIZE bytes from r2 to address (4 + 5)
** parameter 2 and parameter 3 are index, if they are T_REG,
** using their value for index
** 0x0b (T_REG) (T_REG | T_DIR | T_IND) (T_REG | T_DIR)
*/
