/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:01:45 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/31 18:31:20 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		register_range(int value, int min, int max)
{
	if (value >= min && value <= max)
		return (0);
	return (1);
}

int is_register(unsigned char octet)
{
    if (octet == (REG_CODE << 6))
        return (T_REG);
    return (1);
}

int is_indirect(int octet)
{
    if (octet == (IND_CODE << 6))
        return (T_IND);
    return (1);
}

int is_direct(int octet)
{
    if (octet == (DIR_CODE << 6))
        return (T_DIR);
    return (1);
}