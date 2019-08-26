#include "vm.h"

int					ft_get_player_index(t_corewar *cor, int i)
{
	int		j;

	j = 0;
	while (j < cor->nb_players)
	{
		if (cor->player[j].id == i)
			return (j);
		j++;
	}
	return (-1);
}

static inline void	ft_verbosity_output(t_corewar *cor, t_arg arg, int index)
{
	if (cor->verbosity && !cor->visu)
	{
		if (index == -1)
			ft_printf("Live: Player with id %d does not exist.\n",
					arg.value[0]);
		else
			ft_printf("Player %s (id: %d) is alive.\n",
				cor->player[index].name, arg.value[0]);
	}
}

void				inst_live(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;
	int		index;

	ft_print_debug(plst, "LIVE", 0);
	ft_arg_init(&arg, 1, FULL, FALSE);
	arg.type[0] = DIR_CODE;
	arg.size[0] = 4;
	ft_get_args(cor, plst, &arg);
	index = ft_get_player_index(cor, arg.value[0]);
	ft_verbosity_output(cor, arg, index);
	(plst->p.live)++;
	if (index != -1)
	{
		cor->process[cor->nb_players - 1 - index].live++;
		cor->process[cor->nb_players - 1 - index].live_round++;
		cor->last_live_id = arg.value[0];
	}
	cor->live_declared++;
	plst->p.no_live = 0;
	ft_print_debug(plst, "LIVE", 1);
}
