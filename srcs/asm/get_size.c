/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:50:19 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/26 22:35:49 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int get_size(t_param *param, s_op op)
{
    if (param->type == T_REG)
        return (1);
    if (param->type == T_IND)
        return (2);
    if (param->type == T_DIR)
    {
        if (op->opcode == 1 || op->opcode == 2 || op->opcode == 6 ||
            op->opcode == 7 || op->opcode == 8 || op->opcode == 13)
            return (4);
        else
            return (2);
    }
    return (0);
}

