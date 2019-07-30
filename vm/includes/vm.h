/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:35:47 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/30 22:14:52 by hlombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <unistd.h>
# include <fcntl.h>
# include <locale.h>
# include <stdint.h>
# include <stdlib.h>
//# include "op.h"
//# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
#include "../../includes/op.h"
#include "../libft/includes/libft.h"

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
	char				*prog_name;
	char				*comment;
	unsigned int		magic;
	unsigned int		prog_size;

    int                 reg[REG_NUMBER + 1];
    unsigned int        pc;
    unsigned int        carry;
    unsigned int        live;

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
    struct s_op			instruction;

	struct s_process	process[4];

}						t_corewar;


/*
 * DEBUG_TOOLS.c
*/

void				print_process_data(t_corewar *cor, int player_nb);

/*
 * COREWAR.c
*/

void				corewar_quit(char *str);

/*
 * GET_TYPE.c
*/

int					register_range(int value, int min, int max);
int 				is_register(unsigned char octet);
int 				is_indirect(int octet);
int 				is_direct(int octet);

/*
 * PARSING_1.c
*/

int					parse_arguments(char *av);
int					get_infos(int ac, char **av, t_corewar *cor);
//swap_endian doublons, deja present dans asm
uint32_t			swap_endian(uint32_t val);

/*
 * READ_PROCESS.c
*/

void				read_process(char *name, t_corewar *cor, int i);


















#endif
