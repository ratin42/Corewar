#include "../../includes/vm.h"

void	create_arena(t_corewar *cor)
{
	int i;

	i = -1;
	ft_bzero(cor->arena, MEM_SIZE);
	while (++i < cor->nb_players)
	{
		ft_memcpy((void*)&cor->arena + ((MEM_SIZE / cor->nb_players) * i),
				cor->process[i].code, cor->process[i].size);
		cor->process[i].alive = 1;
		cor->process[i].pc = (MEM_SIZE / cor->nb_players) * i;
	}	
	//Init PC de chaque process;
}

void    play(t_corewar *cor)
{
	cor->ctd = CYCLE_TO_DIE;
	while (process_alive(cor) > 0)
	{
		cor->cycle++;
		cor->total++;
		if (cor->verbosity)
			ft_printf("It is now cycle %d\n", cor->total);
		if (cor->total == cor->n_dump)
		{
			print_arena_state(cor);
			break;
		}
		exec_process(cor);
		if (cor->cycle > CYCLE_TO_DIE)
			update_cycles(cor);
	}
	ft_printf("Contestant %d, %s, has won !\n", cor->winner_id,
			cor->process[cor->winner_id].name);
}

int		process_alive(t_corewar *cor)
{
	int		i;
	int		nb;

	nb = 0;
	i = -1;
	while (++i < cor->nb_players)
	{
		if (cor->process[i].alive == 1)
			nb++;	
	}
	return (nb);
}

void    exec_process(t_corewar *cor)
{
	int i;

	i = cor->nb_players;
	while (--i >= 0)
	{
		if (cor->process[i].alive == 1)
		{
			++cor->process[i].no_live;
			execute_code(cor, i);
		}
	}
}

void (*g_func[17])(t_corewar *cor, int i) =
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


void	execute_code(t_corewar *cor, int i)
{
	unsigned char	type;
	int index;

	//Gerer ici aussi la dure/le freeze des processus
	//en fonctions des instructions;
	//ADJUST PC OVERFLOW...
	index = -1;
	type = cor->arena[cor->process[i].pc];
	while (++index < 17)
	{
		if (g_op_tab[index].opcode == type)
		{
			g_func[index](cor, i);
		}
	}

}


















