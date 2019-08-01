/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 22:35:47 by syzhang           #+#    #+#             */
/*   Updated: 2019/08/01 19:54:23 by hlombard         ###   ########.fr       */
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
#include "../libft/libft.h"
#include "../libft/includes/ft_printf.h"

# define DEBUG 0

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
	char				*name;
	char				*comment;
	unsigned int		magic;
	unsigned int		size;
	unsigned char		code[CHAMP_MAX_SIZE];
	
	int					alive;

    int                 reg[REG_NUMBER + 1];
    unsigned int        pc;
    unsigned int        carry;
    unsigned int        live;
	int					id;
}                       t_process;

typedef struct 			s_corewar
{
	unsigned char		arena[MEM_SIZE];
	unsigned int		head;
	unsigned int		tail;
	unsigned int 		ram_full;
	int					count;
	int					last_live_id;
	int					nb_players;
	char				*last_live_name;
	unsigned int		current_live;

    struct s_op			instruction;
	struct s_process	process[MAX_PLAYERS];

	int					cycle;

	int					n_dump;

}						t_corewar;


/*
 * DEBUG_TOOLS.c
*/

void				print_process_data(t_corewar *cor, int player_nb);
void				print_arena_state(t_corewar *cor);
void				corewar_usage(void);
void				corewar_quit(char *str);

/*
 * COREWAR.c
*/

void				init_datas(t_corewar *cor);


/*
 * GET_TYPE.c
*/

int					register_range(int value, int min, int max);
int 				is_register(unsigned char octet);
int 				is_indirect(int octet);
int 				is_direct(int octet);

/*
 * PARSING.c
*/

int					cor_file(char *av);
int					parse_arguments(int ac, char **av, t_corewar *cor);
void				get_champion(t_corewar *cor, char **av, int i, int *player_nb);

//swap_endian doublons, deja present dans asm
uint32_t			swap_endian(uint32_t val);

/*
 * OPTIONS.C
*/

void				dump_option(t_corewar *cor, char **av, int *i);


/*
 * READ_PROCESS.c
*/

void				read_process(char *name, t_corewar *cor, int i);
void				stock_process_size(t_corewar *cor, t_header *header, char *name, int i);
void				stock_process_name(t_corewar *cor, t_header *header, char *name, int i);
void				stock_process_comment(t_corewar *cor, t_header *header, char *name, int i);
void				stock_process_magic(t_corewar *cor, t_header *header, char *name, int i);
void				stock_process_code(t_corewar *cor, int i, int fd);


void				create_arena(t_corewar *cor);


/*
 * START_PLAYING.c
*/

void				start_playing(t_corewar *cor);
int					process_alive(t_corewar *cor);


















#endif
