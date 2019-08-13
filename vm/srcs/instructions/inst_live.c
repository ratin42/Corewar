#include "../../includes/vm.h"

static inline int   ft_get_player_index(t_corewar *cor, int i)
{
	int     j;

	j = 0;
	while (j < MAX_PLAYERS)
	{
		if (cor->player[j].id == i)
			return (j);
		j++;
	}
	return (-1);
}

void                inst_live(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;
	int     index;

	//debug
	//ft_printf("process[%d] : AND\n", i);
	if (DEBUG)
	{
		ft_printf("LIVE\n");
		//ft_printf("live : pc before = %u\n", plst->p.pc);
	}
	ft_arg_init(&arg, 1, FULL, FALSE);
	arg.type[0] = DIR_CODE;
	arg.size[0] = 4;
	ft_get_args(cor, plst, &arg);
	if ((index = ft_get_player_index(cor, arg.value[0])) == -1)
	{
		if (cor->verbosity && !cor->visu)
			ft_printf("Live: Player with id %d does not exist.\n", arg.value[0]);
	}
	if (cor->verbosity && !cor->visu)
		ft_printf("Player %s (id: %d) is alive.\n", cor->player[index].name, arg.value[0]);
	(plst->p.live)++;
	cor->last_live_id = arg.value[0];
	cor->live_declared++;
	plst->p.no_live = 0;
	if (DEBUG)
		ft_printf("live : pc after = %u\n", plst->p.pc);
}
