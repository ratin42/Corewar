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

	if (ac < 2)
	{
		corewar_usage();
		return (0);
	}
	else
	{
		init_datas(&cor);
		parse_arguments(ac, av, &cor);
		create_arena(&cor);	
		//debug_order(&cor);
		//print_arena_state(&cor);
		
	//	play(&cor);

	}
	return (1);
}
