/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:35:47 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/29 23:13:10 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <unistd.h>
# include <fcntl.h>
# include <locale.h>
# include <stdint.h>
# include <stdlib.h>
# include "op.h"

struct					s_type
{
	int					param1;
	int					param2;
	int					param3;
};

typedef struct			s_op
{
	char				*name;
	int					nbr_of_param;
	struct s_type		type_of_param;
	int					opcode;
	int					nbr_of_cycle;
	char				*description;
	unsigned int		coding_opcode;
	unsigned int		direct_size;
}						t_op;

typedef struct          s_process
{
    int                 reg[REG_NUMBER + 1];
    unsigned int        pc;
    unsigned int        carry;
    unsigned int        live;
    t_op                instruction;
    struct s_process    *next;
}                       t_process;

typedef struct          s_champion
{
    char                *name;
    char                *comment;
    int                 id;
    unsigned int        magic;
    unsigned int        prog_size;
}                       t_champion;