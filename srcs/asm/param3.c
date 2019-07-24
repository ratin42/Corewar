/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:08:52 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/24 15:20:26 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int register_range(int value, int min, int max)
{
    if (value >= min && value <= max)
        return (1);
    return (0);
}

int is_register(char *param)
{
    if (*param == 'r' && ft_str_is_numeric(param + 1)
        && register_range(ft_atoi(param + 1), 1, REG_NUMBER))
        return (T_REG);
    return (0);
}