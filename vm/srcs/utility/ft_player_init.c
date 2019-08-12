#include "../../includes/vm.h"

void	ft_player_init(t_corewar *cor)
{
	int		i;
	t_plst	*elem;

	i = 0;
	elem = cor->plst;
	while (i < cor->nb_players)
	{
		ft_memcpy(cor->player[i].name, elem->p.name, PROG_NAME_LENGTH);
		cor->player[i].id = elem->p.id;
		elem = elem->next;
		i++;
	}
}
