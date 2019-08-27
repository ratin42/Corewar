#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <locale.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/uio.h>

# include "../../common_files/libft/libft.h"
# include "../../common_files/libft/includes/ft_printf.h"
# include "struct.h"


# define DEBUG			0
# define TRUE			1
# define FALSE			0
# define SUCCESS		1
# define FAIL			-1
# define FULL			1
# define HALF			2
# define FRST			1
# define SCND			1 << 1
# define THRD			1 << 2

# define BOX_COL_1		COLS / 2 + 15
# define BOX_COL_2		COLS / 5
# define BOX_LINES_1	((LINES / 3) + (LINES / 2)) - 2
# define CMD_LINES		(BOX_LINES_1 / 4)
# define CMD_COLS		(BOX_COL_2 / 2) / 2
# define CMD_STARTY		((CMD_LINES / 2) - 8) - 1
# define CMD_STARTX		(BOX_COL_1 + BOX_COL_2)

# define DARK_GREY		6
# define LIGHT_GREY		7
# define LIGHT_CYAN		5

#define SPACE_BAR		' '
#define QUIT			'q'

#define STR1 " _____ ___________ _____ _    _  ___ ______ "
#define STR2 "/  __ \\  _  | ___ \\  ___| |  | |/ _ \\| ___ \\"
#define STR3 "| /  \\/ | | | |_/ / |__ | |  | / /_\\ \\ |_/ /"
#define STR4 "| |   | | | |    /|  __|| |/\\| |  _  |    / "
#define STR5 "| \\__/\\ \\_/ / |\\ \\| |___\\  /\\  / | | | |\\ \\ "
#define STR6 " \\____/\\___/\\_| \\_\\____/ \\/  \\/\\_| |_|_| \\_|"

#define VERBO_TXT "\nNeed to specify verbosity level after -v option:\n\
				Verbosity levels, can be added together to enable several\n\
				- 1 : Show lives\n\
                - 2 : Show cycles\n\
                - 4 : Show operations (Params are NOT litteral ...)\n\
                - 8 : Show deaths\n\
                - 16 : Show PC movements (Except for jumps)\n"
# define VERBO1 1
# define VERBO2 2
# define VERBO3 4
# define VERBO4	8
# define VERBO5 16
# define NORMAL 1
# define INDIRECT 1 << 1
# define SPECIAL 1 << 2

extern t_op		g_op_tab[17];
/*
 * DEBUG_TOOLS.c
*/

void				print_process_data(t_corewar *cor, int player_nb);
void				print_arena_state(t_corewar *cor);
void				pcode(t_corewar *cor, int pc);
void				debug_order(t_corewar *cor);
void				corewar_usage(void);
void				corewar_quit(char *str);

void				ft_print_process(t_process p);
void				ft_print_debug(t_plst *plst, char *op_name, int end);
void				ft_print_plst(t_plst *plst);
void	ft_print_args(t_arg arg);

/*
 * NCURSES
*/

//ncurses_button.c

void				draw_play(t_corewar *cor);
void				draw_play_1(t_corewar *cor, int x, int x1, int y1);
void				draw_play_2(t_corewar *cor, int x, int x1, int y);
void				draw_pause(t_corewar *cor);

//ncurses_draw.c

void				draw_arena(t_corewar *cor);
void				draw_window(t_corewar *cor);
void				draw_menu(t_corewar *cor);
void				update_window(t_corewar *cor);

//ncurses_events.c

void				ncurse_events(t_corewar *cor);
void				manage_events(t_corewar *cor, int keycode);
void				pause_game(t_corewar *cor);
void				manage_pause(t_corewar *cor, int keycode);

//ncurses_fill_border.c

void				fill_border_main(t_corewar *cor);
void				fill_border_menu(t_corewar *cor);
void				fill_border_cmd(t_corewar *cor);

//ncurses_init.c

void				init_ncurse(t_corewar *cor);
void				init_colors(void);

//ncurses_menu.c

void				draw_player_info(t_corewar *cor);
void				draw_infos(t_corewar *cor);
void				draw_banner(t_corewar *cor);
void				draw_command(t_corewar *cor);

//ncurses_utility.c

void				highlight_process_pc(t_corewar *cor);
void				highlight_it(t_corewar *cor, unsigned int i, int id);
void				set_attributes(t_corewar *cor, unsigned char color, int i);
void				unset_attributes(t_corewar *cor, unsigned char color, int i);
int					re_adjust_id(int id, t_process *pro);

//ncurses_close.c

void				wait_and_close(int wait);
void				ncurses_show_winner(t_corewar *cor);
void				close_ncurses(t_corewar *cor);
void				end_visu(t_corewar *cor);


/*
 * COREWAR.c
*/


/*
 * PARSING.c
*/

int					cor_file(char *av);
void				parse_arguments(int ac, char **av, t_corewar *cor);
void				get_champion(t_corewar *cor, char **av, int i);
void				order_process(t_corewar *cor);

/*
 * OPTIONS.C
*/

void				dump_option(t_corewar *cor, char **av, int *i);
void				verbosity_option(t_corewar *cor, char **av, int ac, int *i);
void				order_option(t_corewar *cor, char **av, int *i);
void				ft_verbosity_instru(t_corewar *cor, t_plst *plst, t_arg arg);

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
t_plst				*ft_plst_init(t_corewar *cor);
void				update_pc(t_corewar *cor, int i);
void				pc_modulo2(t_plst *plst, int i);
int					pc_modulo(int pc);
int					get_reg_index(t_corewar *cor, t_plst *plst);
int					*check_opcode(t_corewar *cor, t_plst *plst);
int					check_registre_index(int reg_1, int reg_2, int reg_3);
int					ft_check_reg_index(t_arg arg);
int					get_reg_value(t_corewar *cor, t_plst *plst, int **f_error);
int					get_small_dir(t_corewar *cor, t_plst *plst);
int					get_ind(t_corewar *cor, t_plst *plst);
void				print_value(t_corewar *cor, int value, int addr, t_plst *plst);

int					ft_check_arg_type(t_arg arg, int i, int code1, int code2);
void				ft_player_init(t_corewar *cor);
int					ft_get_restricted_addr(int value);
void				init_plst(t_corewar *cor);

/*						INSTRUCTIONS						*/

void				inst_add(t_corewar *cor, t_plst *plst);
void				inst_aff(t_corewar *cor, t_plst *plst);
void				inst_and(t_corewar *cor, t_plst *plst);
void				inst_fork(t_corewar *cor, t_plst *plst);
void				inst_ld(t_corewar *cor, t_plst *plst);
void				inst_ldi(t_corewar *cor, t_plst *plst);
void				inst_lfork(t_corewar *cor, t_plst *plst);

void				inst_live(t_corewar *cor, t_plst *plst);
int					ft_get_player_index(t_corewar *cor, int i);

void				inst_lld(t_corewar *cor, t_plst *plst);
void				inst_lldi(t_corewar *cor, t_plst *plst);
void				inst_or(t_corewar *cor, t_plst *plst);
void				inst_st(t_corewar *cor, t_plst *plst);
void				inst_sti(t_corewar *cor, t_plst *plst);
void				inst_sub(t_corewar *cor, t_plst *plst);
void				inst_xor(t_corewar *cor, t_plst *plst);
void				inst_zjmp(t_corewar *cor, t_plst *plst);

/*
 * ARG MANIPULATORS
*/

void	ft_arg_init(t_arg *arg, int nb_arg, int dir_size,
	int addr_restrict, int verbo);
void	ft_get_opcode(t_corewar *cor, t_plst *plst, t_arg *arg);
void	ft_get_args_size(t_arg *arg);
void	ft_get_args(t_corewar *cor, t_plst *plst, t_arg *arg);
void	ft_get_reg_value(t_arg *arg, t_plst *plst, int pos);




void			corewar_end(t_corewar *cor);
void			introducing_contestants(t_corewar *cor);



#endif
