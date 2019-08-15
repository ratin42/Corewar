#include "../includes/vm.h"

//Connaitre le size min d'un champion pour rejeter comme zaz;

static inline void	create_arena(t_corewar *cor)
{
	int		i;

	i = -1;
 	if (cor->visu)
		init_ncurse(cor);
	ft_bzero(cor->arena, MEM_SIZE);
	while (++i < cor->nb_players)
	{
		ft_memcpy((void*)&cor->arena + ((MEM_SIZE / cor->nb_players) * i),
				cor->process[i].code, cor->process[i].size);
		cor->process[i].pc = (MEM_SIZE / cor->nb_players) * i;
		if (cor->visu)
		{
			ft_memset(cor->render.mem_owner + ((MEM_SIZE / cor->nb_players)
						* i), (char)(i + 2), cor->process[i].size);
		}
	}
}

static inline void	init_datas(t_corewar *cor)
{
	ft_bzero(cor, sizeof(t_corewar));
	cor->n_dump = -1;
}

int					main(int ac, char **av)
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
		introducing_contestants(&cor);	
		//debug_order(&cor);
		//print_arena_state(&cor);
		play(&cor);
		corewar_end(&cor);
	}
	return (1);
}

void			corewar_end(t_corewar *cor)
{
	int		winner;

	if (cor->visu)
		close_ncurse(cor);

	//FREE_CE_QU'IL FAUT;	

	winner = cor->last_live_id;
	if (!cor->hide_winner)
	{
		if (winner == 0)
			ft_printf("No contestant managed to make a succesful live. DRAW\n");
		else
			ft_printf("Contestant %d, \"%s\", has won !\n", winner,
				cor->player[ft_get_player_index(cor, winner)].name);
	}
}


//TODO
// probleme sti quand plusieurs process
// Voir pour le numero des joueurs qui est negatif sur la vm de zazz
// 1 : Show lives
// 2 : Show cycles
// 4 : Show operations (Params are NOT litteral ...)
// 8 : Show deaths
// 16 : Show PC movements (Except for jumps)

//BONUS faire un man

