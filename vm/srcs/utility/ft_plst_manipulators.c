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

void	add_plst(t_corewar *cor, int i)
{
	t_plst	*new_plst;
	t_plst	*plst;

	if (!(new_plst = malloc(sizeof(t_plst))))
		corewar_quit("malloc error\n");
	plst = cor->plst;
	ft_memcpy(&(new_plst->p), cor->process + i, sizeof(t_process));
	if (cor->plst == NULL)
		cor->plst = new_plst;
	else
	{
		while (plst->next)
			plst = plst->next;
		plst->next = new_plst;
	}
}

void		init_plst(t_corewar *cor)
{
	int		i;
	
	i = 0;
	while (i < cor->nb_players)
	{
		add_plst(cor, i);
		i++;
	}
}
