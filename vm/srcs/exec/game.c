#include "../../includes/vm.h"

t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR, 0, 0}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG, 0}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR, 0, 0}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR, 0, 0}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR, 0, 0}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG, 0, 0}, 16, 2, "aff", 1, 0},
	{0, 0, {0, 0, 0}, 0, 0, 0, 0, 0}
};

void (*g_func[17])(t_corewar *cor, t_plst *plst) =
{
	NULL,//inst_live,
	NULL,//inst_ld,
	inst_st,
	inst_add,
	inst_sub,
	NULL,//inst_and,
	NULL,//inst_or,
	NULL,//inst_xor,
	NULL,//inst_zjmp,
	NULL,//inst_ldi,
	inst_sti,
	NULL,//inst_fork,
	NULL,//inst_lld,
	NULL,//inst_lldi,
	NULL,//inst_lfork,
	inst_aff
};

static inline void	ft_get_instru(t_corewar *cor, t_plst *plst)
{
	if (cor->arena[plst->p.pc] <= 17 && cor->arena[plst->p.pc] >= 1)
	{
		plst->p.opcode = cor->arena[plst->p.pc];
		plst->p.wait = g_op_tab[plst->p.opcode - 1].nbr_of_cycle; //wait
	}
	else
	{
		plst->p.pc = pc_modulo(plst->p.pc + 1);
		plst->p.opcode = 0;
	}
}

static inline void	execute_code(t_corewar *cor, t_plst *plst)
{
	g_func[plst->p.opcode - 1](cor, plst);
	plst->p.opcode = 0;
}

static inline void	exec_process(t_corewar *cor)
{
	t_plst	*plst;

	plst = cor->plst;
	while (plst != NULL)
	{
		plst->p.no_live++;
		if (plst->p.opcode == 0)
			ft_get_instru(cor, plst);
		else
		{
			plst->p.wait--;
			//plst->p.wait = 0; // pour la compilation
			if (plst->p.wait == 0)
				execute_code(cor, plst);
		}
		plst = plst->next;
	}
}

void				play(t_corewar *cor)
{
	t_plst	*plst;

	if (!(plst = ft_plst_init(cor)))
		corewar_quit("Malloc error");
	cor->ctd = CYCLE_TO_DIE;
	cor->plst = plst; // j'ai rajoute ca pour que ca compile
	if (cor->visu)
		cor->pause = 1; // si le visu alors la partie commence en pause
	while (cor->plst != NULL)
	{
		if (cor->visu)
		{
			//ncurse_events(cor);
			//draw_window(cor);
		}
		ft_printf("%d\n", cor->total);
		cor->cycle++;
		cor->total++;
		if (cor->verbosity)
			ft_printf("It is now cycle %d\n", cor->total);
		exec_process(cor);
		if (cor->total == cor->n_dump)
		{
			print_arena_state(cor);
			return; //Est ce qu'il faut afficher le gagnant ?
			//Non mais du coup il faudrait pas free en dessous j'ai return
			//il faut free dans la fonction d'apres du main;
		}
		if (cor->cycle > cor->ctd) // je mettrais >=
			update_cycles(cor);
	}
	ft_printf("Contestant %d, %s, has won !\n", cor->winner_id,
			cor->process[cor->winner_id].name); //need change
}
