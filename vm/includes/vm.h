/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:35:47 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/30 16:57:57 by syzhang          ###   ########.fr       */
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
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
//#include "../../includes/op.h"
//#include "../libft/includes/libft.h"

# include <stdio.h>

# define DEBUG 1

typedef struct			s_type
{
	int					param1;
	int					param2;
	int					param3;
}                       t_type;

typedef struct			s_op
{
	char				*name;
	int					nbr_of_param;
	t_type	        	type_of_param;
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

typedef struct 			s_corewar
{
	unsigned char		ram[MEM_SIZE];
	unsigned int		head;
	unsigned int		tail;
	unsigned int 		ram_full;
	int					count;
}						t_corewar;

typedef	struct		s_instru
{
//
}					t_instru;

typedef	struct		s_process
{
	struct s_header		header;
	struct s_instru		*instru;

}					t_process;


uint32_t	swap_endian(uint32_t val);

void	corewar_quit(char *str);
void	read_process(char *name);
int		parse_arguments(char *av);
int		get_infos(int ac, char **av);

#endif