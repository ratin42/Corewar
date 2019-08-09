#include "../../includes/vm.h"

static inline void    ft_kill_no_live_process(t_corewar *cor)
{
	t_plst	*plst;
	t_plst	*elem;

	plst = cor->plst;
	while (plst->p.live == 0)
	{
		if (cor->verbosity)
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					plst->p.id, plst->p.no_live, cor->ctd);
		cor->plst = plst->next;
		free(plst);
		plst = cor->plst;
		if (plst == NULL)
			return ;
	}
	while (plst->next != NULL)
	{
		if (plst->p.live == 0)
		{
			if (cor->verbosity)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					plst->p.id, plst->p.no_live, cor->ctd);
			elem = plst->next;
			plst->next = plst->next->next;
			free(elem);
		}
		plst = plst->next;
	}
}

static inline void    reset_process_nb_live(t_corewar *cor)
{
	t_plst	*plst;

	plst = cor->plst;
	while (plst != NULL)
	{
		plst->p.live = 0;
		plst = plst->next;
	}
	cor->live_declared = 0;
}

void    update_cycles(t_corewar *cor)
{
	cor->check_cycle++;
	cor->cycle = 0;
	ft_kill_no_live_process(cor);//need to stop here if no process alive?
	if (cor->live_declared >= NBR_LIVE || cor->check_cycle == MAX_CHECKS)
	{
		cor->ctd -= CYCLE_DELTA;
		if (cor->verbosity)
			ft_printf("Cycle to die is now %d\n", cor->ctd);
		cor->check_cycle = 0;
		reset_process_nb_live(cor);
	}
}
