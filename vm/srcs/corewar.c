#include "../includes/vm.h"

//Connaitre le size min d'un champion pour rejeter comme zaz;

void	init_datas(t_corewar *cor)
{
	ft_bzero(cor, sizeof(t_corewar));
	cor->n_dump = -1;
}

int main(int ac, char **av)
{
	t_corewar	cor;

	if (ac <= 1)
		return (0);
	else
	{
		init_datas(&cor);
		parse_arguments(ac, av, &cor);
		create_arena(&cor);
		// print_arena_state(&cor);

	}
	return (1);
}

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
