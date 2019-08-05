#include "../includes/vm.h"

void    update_cycles(t_corewar *cor)
{
	cor->check_cycle++;
	cor->cycle = 0;
	check_process_to_kill(cor);
	if (cor->live_declared >= NBR_LIVE || cor->check_cycle == MAX_CHECKS)
	{
		cor->ctd -= CYCLE_DELTA;
		if (cor->verbosity)
			ft_printf("Cycle to die is now %d\n", cor->ctd);
		cor->check_cycle = 0;
		reset_process_nb_live(cor);
		cor->live_declared = 0;
	}
}

void    reset_process_nb_live(t_corewar *cor)
{
	int i;

	i = -1;
	while (++i < cor->nb_players)
	{
		if (cor->process[i].alive == 1)
			cor->process[i].live = 0;
	}
}

void    check_process_to_kill(t_corewar *cor)
{
	int i;

	i = -1;
	while (++i < cor->nb_players)
	{
		if (cor->process[i].no_live >= cor->ctd && cor->process[i].alive == 1)
		{
			if (cor->verbosity)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					i, cor->process[i].no_live, cor->ctd);
			cor->process[i].live = 0;
			cor->process[i].alive = 0;
		}
	}
}
