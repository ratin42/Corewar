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

static inline int	ft_get_player_name(t_corewar *cor)
{
	int		i;
	char	*name;

	i = 0;
	while (i < cor->nb_players)
	{
		if (!(name = ft_strdup(cor->process[i].name)))
			return (FAIL);
		if (cor->process[i].order == -1)
		{
			cor->player_name[i] = name;
			cor->process[i].reg[1] = i;
		}
		else
		{
			cor->player_name[cor->process[i].order] = name;
			cor->process[i].reg[1] = cor->process[i].order;
		}
		i++;
	}
	return (SUCCESS);
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
		if (ft_get_player_name(&cor) == FAIL)
			return (0);
		create_arena(&cor);	

		//debug_order(&cor);
		//print_arena_state(&cor);
		play(&cor);

	}
	return (1);
}

//TODO

// Voir pour le numero des joueurs qui est negatif sur la vm de zazz

//BONUS faire un man
// 1 : Show lives
// 2 : Show cycles
// 4 : Show operations (Params are NOT litteral ...)
// 8 : Show deaths
// 16 : Show PC movements (Except for jumps)

//BONUS faire un man

