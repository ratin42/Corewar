#include <stdlib.h>
#include "vm.h"

t_plst	*ft_plst_init(t_corewar *cor)
{
	int			i;
	t_plst		*plst;
	t_plst		*elem;

	i = 0;
	while (i < cor->nb_players)
	{
		if (!(elem = malloc(sizeof(t_plst))))
			return (NULL);
		ft_memcpy(&(elem->p), cor->process + i, sizeof(t_process));
		elem->next = NULL;
		plst = elem;
		i++;
		plst->p.id = plst->p.order == -1 ? i : plst->p.order;
		plst->p.reg[1] = plst->p.id;
	}
	return (plst);
}
