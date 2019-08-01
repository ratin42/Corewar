#include "../includes/vm.h"

void	create_arena(t_corewar *cor)
{
	int i;

	i = -1;
	
	//init more things in while or before here
	ft_bzero(cor->arena, MEM_SIZE);
	while (++i < cor->nb_players)
	{
		cor->process[i].alive = 1;
		//more inits ?
		ft_memcpy((void*)&cor->arena + ((MEM_SIZE / cor->nb_players) * i),
				cor->process[i].code, cor->process[i].size);
	}
}

void	start_playing(t_corwar *cor)
{
	while (process_alive(cor) > 0)
	{
		if (core->cycle == cor->n_dump)
		{
			print_arena_state(cor);
			break;
		}
		//manage game;
	}
}

int		process_alive(t_corewar *cor)
{
	int		i;
	int		nb;

	nb = 0;
	i = -1;
	while (++i < cor->nb_players)
	{
		if (cor->process[i].alive == 1)
			nb++;	
	}
	return (nb);
}
