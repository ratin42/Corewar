/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:51:47 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/31 19:40:35 by hlombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int ft_live(t_corewar *corewar, t_process *champion, t_op *opcode)
{
    if (opcode->type_of_param.param1 == T_DIR)
    {
        ft_printf("le joueur %d(%s) est en vie\n", champion->id, champion->name);
        champion->live = 1;
        corewar->last_live_id = champion->id;
        corewar->last_live_name = champion->name;
        corewar->current_live += 1;
    }
    return (0);
}
