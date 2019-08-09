#include "../../includes/vm.h"

void	print_memowner_state(t_corewar *cor)
{
	int p;
	int j;
	int i;

	j = 0;
	p = 0;
	i = -1;
	while (++i < MEM_SIZE)
	{
		if (j == 64 || i == 0)
		{
			ft_putchar('\n');
			ft_printf("0x%.4x : ", p);
			p += 64;
			j = 0;
		}
		ft_printf("%.2x ", cor->render.mem_owner[i]);
		j++;

	}
	ft_printf("\n");
}


void	create_arena(t_corewar *cor)
{
	int i;

	i = -1;
	if (cor->visu)
		init_ncurse(cor);
	ft_bzero(cor->arena, MEM_SIZE);
	while (++i < cor->nb_players)
	{
		ft_memcpy((void*)&cor->arena + ((MEM_SIZE / cor->nb_players) * i),
				cor->process[i].code, cor->process[i].size);
		cor->process[i].alive = 1;
		cor->process[i].pc = (MEM_SIZE / cor->nb_players) * i;
		if (cor->visu)
		{
			ft_memset(cor->render.mem_owner + ((MEM_SIZE / cor->nb_players)
				* i), (char)(i + 1), cor->process[i].size);
		}
	}
	//print_memowner_state(cor);
	if (cor->visu)
	{
		draw_default_mem(cor);
		close_ncurse(cor);
	}

}

void    play(t_corewar *cor)
{
	t_plst	*plst;

	if (!(plst = ft_plst_init(cor)))
		corewarquit("Malloc error");
	cor->ctd = CYCLE_TO_DIE;
	while (cor->plst != NULL)
	{
		cor->cycle++;
		cor->total++;
		if (cor->verbosity)
			ft_printf("It is now cycle %d\n", cor->total);
		exec_process(cor);
		if (cor->total == cor->n_dump)
		{
			print_arena_state(cor);
			break; //Est ce qu'il faut afficher le gagnant ?
		}
		if (cor->cycle > cor->ctd) // je mettrais >=
			update_cycles(cor);
	}
	ft_printf("Contestant %d, %s, has won !\n", cor->winner_id,
			cor->process[cor->winner_id].name); //need change
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
	t_plst	*plst;

	plst = cor->plst;
	while (plst != NULL)
	{
		plst->p.no_live++;
		plst->p.wait--;
		if (plst->p.wait == 0)
			execute_code(cor, i);
		plst = plst->next;
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
	int				index;

	//adjust_pc_overflow(cor, i);
	index = -1;

	type = cor->arena[cor->process[i].pc];
	while (++index < 17)
	{
		if (g_op_tab[index].opcode == type)
		{
			g_func[index](cor, i);

			exit(-1);
		}
	}

}
