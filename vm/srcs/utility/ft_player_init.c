#include "vm.h"

void	ft_player_init(t_corewar *cor)
{
	int		i;
	int 	j;
	t_plst	*elem;

	i = 0;
	elem = cor->plst;
	j = cor->nb_players;
	while (i < cor->nb_players)
	{
		ft_memcpy(cor->player[i].name, elem->p.name, PROG_NAME_LENGTH);
		cor->player[i].id = elem->p.id;
		if (elem->p.order != -1)
			elem->p.order = j;
		elem = elem->next;
		j--;
		i++;
	}
}
