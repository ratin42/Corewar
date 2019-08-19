#ifndef	STRUCT_H
# define STRUCT_H

# include <ncurses.h>
# include "../../common_files/op.h"

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
	WINDOW				*commands;
	char				*color_types;
	unsigned char		mem_owner[MEM_SIZE];
	unsigned char		bold[MEM_SIZE];
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
	char				name[PROG_NAME_LENGTH];// il faudrait pas un +1 ici ?
	char				comment[COMMENT_LENGTH];
	unsigned int		magic;
	unsigned int		size;
	unsigned char		code[CHAMP_MAX_SIZE];
	int					order;
	int					id;
	int					reg[REG_NUMBER + 1];
	unsigned int		pc;
	unsigned int		og_pc;
	unsigned int		carry;
	unsigned int		live;
	unsigned int		live_round;

	int					no_live;
	unsigned int		wait;
	int					opcode;
}                       t_process;

typedef struct			s_plst
{
	struct s_plst		*next;
	int					id;
	t_process			p;
}						t_plst;

typedef struct			s_player
{
	char				name[PROG_NAME_LENGTH + 1];
	int					id;
}						t_player;

typedef struct 			s_corewar
{
	unsigned char		arena[MEM_SIZE];
	unsigned int 		ram_full;
	int					count;
	int					last_live_id;
	int					nb_players;
	t_player			player[4];
	int					nb_process;
	unsigned int		current_live;
	int					cycle;
	int					total_cycle;
	int					ctd;
	int					live_declared;
	int					check_cycle;

	int					round_end;

	t_plst				*plst;

	int					n_dump;
	int					verbosity;
	int					order;
	int					order_option;
	int					stealth;
	int					visu;
	int					pause;
	int					sleep;

	int					winner_id; //on garde ou pas ?
	int					hide_winner;

	struct s_op			instru;
	struct s_process	process[MAX_PLAYERS];
	struct s_render		render;

}						t_corewar;

typedef	struct			s_arg
{
	int					nb_arg;
	t_arg_type			type[4];
	unsigned int		size[4];
	int					value[4];
	int					dir_size;
	int					addr_restrict;
}						t_arg;

#endif
