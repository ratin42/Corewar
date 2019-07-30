/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 23:01:45 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/30 15:07:05 by syzhang          ###   ########.fr       */
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
    if (octet == 0b01000000)
        return (0);
    return (1);
}

int is_indirect(int octet)
{
    if (octet == 0b11000000)
        return (0);
    return (1);
}

int is_direct(int octet)
{
    if (octet == 0b10000000)
        return (0);
    return (1);
}

// int main()
// {
//     int byte = 0b01000000;
//     printf("ret = %d", is_register(byte));
//     return 0;
// }