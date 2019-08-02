/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:18:01 by qtran             #+#    #+#             */
/*   Updated: 2019/08/01 14:18:02 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** Instructions:
** Take a registry and a registry or an indirect and store the value of the
** registry toward a second argument. Its opcode is 0x03. For example, st r1, 42
** store the value of r1 at the address (PC + (42 % IDX_MOD))
** 0x03 (T_REG) (T_REG | T_IND) -
*/

int op_st(t_corewar *cor, t_process *process, uint16_t ins)
{
  uint8_t ocp;

  ocp = ft_get_ocp(ins);

}
