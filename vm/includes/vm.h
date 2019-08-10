#ifndef VM_H
# define VM_H

# include <unistd.h>
# include <fcntl.h>
# include <locale.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../../asm/includes/op.h"
# include "../libft/libft.h"
# include "../libft/includes/ft_printf.h"
# include <ncurses.h>


# define DEBUG			0
# define SUCCESS		1
# define FAIL			-1

//	VISU DEFINES //

# define BOX_COL_1		COLS / 2 + 15
# define BOX_COL_2		COLS / 5
# define BOX_LINES_1	((LINES / 3) + (LINES / 2)) - 2

# define DARK_GREY		6
# define LIGHT_GREY		7

typedef struct			s_type
{
	int					param1;
	int					param2;
	int					param3;
}						t_type;

typedef struct			s_render
{
	WINDOW				*main;
	WINDOW				*menu;
	char				*color_types;
	unsigned char		mem_owner[MEM_SIZE];
}						t_render;

typedef struct			s_op
{
	char				*name;
	int					nbr_of_param;
	t_type				type_of_param;
	int					opcode;
	int					nbr_of_cycle;
	char				*description;
	unsigned int		coding_opcode;
	unsigned int		direct_size;
}						t_op;

typedef struct			s_process
{
	char				name[PROG_NAME_LENGTH];
	char				comment[COMMENT_LENGTH];
	unsigned int		magic;
	unsigned int		size;
	unsigned char		code[CHAMP_MAX_SIZE];
	int					order;
	int					id;
	int					reg[REG_NUMBER + 1];
	unsigned int		pc;
	unsigned int		carry;
	unsigned int		live;
	int					no_live;
	unsigned int		wait;
	int					opcode;
}                       t_process;

typedef struct			s_plst
{
	struct s_plst		*next;
	t_process			p;
}						t_plst;

typedef struct 			s_corewar
{
	unsigned char		arena[MEM_SIZE];
	unsigned int 		ram_full;
	int					count;
	int					last_live_id;
	int					nb_players;
	char				*player_name[4];
	unsigned int		current_live;

    struct s_op			instru;
	struct s_process	process[MAX_PLAYERS];
	struct s_render		render;

	int					cycle;
	int					total;
	int					ctd;
	int					live_declared;
	int					check_cycle;

	t_plst				*plst;

	//option

	int					n_dump;
	int					verbosity;
	int					order;
	int					order_option;
	int					stealth;
	int					visu;
	
	int					winner_id;

}						t_corewar;

/*
 * DEBUG_TOOLS.c
*/

void				print_process_data(t_corewar *cor, int player_nb);
void				print_arena_state(t_corewar *cor);
void				pcode(t_corewar *cor, int pc);
void				debug_order(t_corewar *cor);
void				corewar_usage(void);
void				corewar_quit(char *str);

/*
 * NCURSES
*/

void				init_ncurse(t_corewar *cor);
void				init_colors(t_corewar *cor);

void				draw_window(t_corewar *cor);

void				draw_arena(t_corewar *cor);
void				fill_border_main(t_corewar *cor);
void				fill_border_menu(t_corewar *cor);


void				close_ncurse(t_corewar *cor);

/*
 * COREWAR.c
*/

/*
 * GET_TYPE.c
*/

int					register_range(int value, int min, int max);
int 				is_register(int octet);
int 				is_indirect(int octet);
int 				is_direct(int octet);

/*
 * PARSING.c
*/

int					cor_file(char *av);
int					parse_arguments(int ac, char **av, t_corewar *cor);
void				get_champion(t_corewar *cor, char **av, int i);
void				order_process(t_corewar *cor);

/*
 * OPTIONS.C
*/

void				dump_option(t_corewar *cor, char **av, int *i);
void				verbosity_option(t_corewar *cor, char **av, int *i);
void				order_option(t_corewar *cor, char **av, int *i);

/*
 * ORDERS.c
*/

int					check_doubles_order(t_corewar *cor);
void				swap_process(t_corewar *cor, int i, int j);
int					order_available(t_corewar *cor, int one, int two, int three);
void				attribute_order(t_corewar *cor);
void				reorder_process(t_corewar *cor);


/*
 * swap_endian doublons, deja present dans asm
*/
uint32_t			swap_endian(uint32_t val);

/*
 * READ_PROCESS.c
*/

void				read_process(char *name, t_corewar *cor, int i);
void				stock_process_size(t_corewar *cor, t_header *header, char *name, int i);
void				stock_process_name(t_corewar *cor, t_header *header, char *name, int i);
void				stock_process_comment(t_corewar *cor, t_header *header, char *name, int i);
void				stock_process_magic(t_corewar *cor, t_header *header, char *name, int i);
void				stock_process_code(t_corewar *cor, int i, int fd);

/*
 * GAME.c
*/

void				play(t_corewar *cor);

/*
 * CYCLE.C
*/

void				update_cycles(t_corewar *cor);


/*
 * UTILITY
*/
void				update_pc(t_corewar *cor, int i);
int					pc_modulo(int pc);
int					get_reg_index(t_corewar *cor, t_plst *plst);
int					*check_opcode(t_corewar *cor, t_plst *plst);
t_plst				*ft_plst_init(t_corewar *cor);
int		check_registre_index(int reg_1, int reg_2, int reg_3, t_plst *plst);

/*						INSTRUCTIONS						*/

void				inst_add(t_corewar *cor, t_plst *plst);
void				inst_aff(t_corewar *cor, t_plst *plst);
void				inst_and(t_corewar *cor, t_plst *plst);
void				inst_fork(t_corewar *cor, t_plst *plst);
void				inst_ld(t_corewar *cor, t_plst *plst);
void				inst_ldi(t_corewar *cor, t_plst *plst);
void				inst_lfork(t_corewar *cor, t_plst *plst);
void				inst_live(t_corewar *cor, t_plst *plst);
void				inst_lld(t_corewar *cor, t_plst *plst);
void				inst_lldi(t_corewar *cor, t_plst *plst);
void				inst_or(t_corewar *cor, t_plst *plst);
void				inst_st(t_corewar *cor, t_plst *plst);
void				inst_sti(t_corewar *cor, t_plst *plst);
void				inst_sub(t_corewar *cor, t_plst *plst);
void				inst_xor(t_corewar *cor, t_plst *plst);
void				inst_zjmp(t_corewar *cor, t_plst *plst);

#endif
