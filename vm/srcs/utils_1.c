#include "../includes/vm.h"

void	swap_process(t_corewar *cor, int i, int j)
{
	t_process	tmp;

	tmp = cor->process[i];
	cor->process[i] = cor->process[j];
	cor->process[j] = tmp;
}

int		order_available(t_corewar *cor, int one, int two, int three)
{
	int i;

	i = -1;
	while (++i < cor->nb_players)
	{
		if (cor->process[i].order != 1)
			one++;
		if (cor->process[i].order != 2)
			two++;
		if (cor->process[i].order != 3)
			three++;
	}
	if (one == cor->nb_players)
		return (1);
	if (two == cor->nb_players)
		return (2);
	if (three == cor->nb_players)
		return (3);
	return (4);

}

void	adjust_order(t_corewar *cor)
{
	int i;
	int nb;

	i = cor->nb_players;
	while (--i >= 0)
	{
		if (cor->process[i].order == -1)
		{
			nb = order_available(cor, 0, 0, 0);
			cor->process[i].order = nb;
		}
	}
}

int		check_doubles_order(t_corewar *cor)
{
	int i;
	int j;

	i = -1;
	while (++i < cor->nb_players)
	{
		j = i;
		while (++j < cor->nb_players)
		{
			if (cor->process[i].order == cor->process[j].order && cor->process[i].order != -1)
				return (0);
			else if (cor->process[i].order != -1 && cor->process[i].order > cor->process[j].order)
				swap_process(cor, i, j);
		}
	}
	return (1);
}


//Fonction DOUBLONS deja presente dans asm.c

uint32_t	swap_endian(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}