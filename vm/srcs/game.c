#include "../includes/vm.h"

void	create_arena(t_corewar *cor)
{
	int i;

	i = -1;
	ft_bzero(cor->arena, MEM_SIZE);
	while (++i < cor->nb_players)
	{
		cor->process[i].alive = 1;
		ft_memcpy((void*)&cor->arena + ((MEM_SIZE / cor->nb_players) * i),
				cor->process[i].code, cor->process[i].size);
	}
}

void    play(t_corewar *cor)
{
	cor->ctd = CYCLE_TO_DIE;
	//Init PC de chaque process;
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
	ft_printf("Contestant %d, %s, has won !", cor->winner_id,
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
	//Le dernier processus joue en premier;	
	i = cor->nb_players;
	while (--i >= 0)
	{
		if (cor->process[i].alive == 1)
		{
			++cor->process[i].no_live;
			//EXECUTE_CODE
		}
	}
}

/*

void	execute_code(t_corewar *cor)
{
	int	reader;

	reader = 0;
	get_opcode = cor->arena[cor->process[i].pc];
	//tableau de pointeur de fonction, qu irentre dans la fonction de lopcode;
	//selon la fct on rcpr un  nb de parametre
	//
	//dans la meme fct a la fin on augmente le pc du process;
	//
}

*/























