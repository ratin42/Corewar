/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:20:54 by qtran             #+#    #+#             */
/*   Updated: 2019/08/01 14:20:55 by qtran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
** Instructions: Apply an & (bit-to-bit AND) over the first two arguments
** and store the result in a registry, which is the third argument.
** Opcode 0x06. Modifies the carry.
*/
