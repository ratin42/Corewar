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
	inst_live,
	inst_ld,
	inst_st,
	inst_add,
	inst_sub,
	inst_and,
	inst_or,
	inst_xor,
	inst_zjmp,
	inst_ldi,
	inst_sti,
	inst_fork,
	inst_lld,
	inst_lldi,
	inst_lfork,
	inst_aff
};

static inline void	ft_get_instru(t_corewar *cor, t_plst *plst)
{
	if (cor->arena[plst->p.pc] <= 17 && cor->arena[plst->p.pc] >= 1)
	{
		// if (DEBUG)
		// 	ft_printf("pc exec = %u\n", plst->p.pc);
		plst->p.opcode = cor->arena[plst->p.pc];
		plst->p.og_pc = plst->p.pc;
		// if (DEBUG)
		// 	ft_printf("opcode = %d\n", plst->p.opcode);
		plst->p.wait = g_op_tab[plst->p.opcode - 1].nbr_of_cycle - 1; //wait
		// // verifier s'il faut vraiment le -1 ou pas.
		// if (DEBUG)
		// 	ft_printf("wait = %d\n", plst->p.wait);
	}
	else
		plst->p.opcode = 0;
	plst->p.pc = pc_modulo(plst->p.pc + 1);
}

static inline void	execute_code(t_corewar *cor, t_plst *plst)
{
	//if (DEBUG)
	//	ft_printf("opcode exec = %d\n", plst->p.opcode);
	
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
			if (plst->p.wait == 0)
				execute_code(cor, plst);
		}
		plst = plst->next;
	}
}

void				play(t_corewar *cor)
{
	if (cor->visu)
		draw_window(cor);
	while (cor->plst != NULL)
	{
		if (cor->visu)
			update_window(cor);
		cor->cycle++;
		cor->total_cycle++;
		if (cor->verbosity && !cor->visu)
			ft_printf("It is now cycle %d\n", cor->total_cycle);
		exec_process(cor);
		if (cor->total_cycle == cor->n_dump)
		{
			print_arena_state(cor);
			cor->hide_winner = 1;
			return;
		}
		if (cor->cycle > cor->ctd) // je mettrais >=
			update_cycles(cor);
	}
}

void			introducing_contestants(t_corewar *cor)
{
	int		i;
	
	i = -1;
	if (!cor->visu)
	{
		ft_printf("Introducing contestants...\n");
		while (++i < cor->nb_players)
		{
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				i + 1, cor->process[i].size, cor->process[i].name,
					cor->process[i].comment);
		}
	}
	if (!(cor->plst = ft_plst_init(cor)))
		corewar_quit("Malloc error");
	//init_plst(cor);
	cor->ctd = CYCLE_TO_DIE;
	ft_player_init(cor);
}
