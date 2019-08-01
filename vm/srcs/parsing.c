#include "../includes/vm.h"

int		parse_arguments(int ac, char **av, t_corewar *cor)
{
	int i;
	int player_nb;

	player_nb = 0;
	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-d"))
			dump_option(cor, av, &i);
		else if (cor_file(av[i]) == 1)
			get_champion(cor, av, i, &player_nb);
		else
		{
			corewar_usage();
			corewar_quit("");
		}
	}
	if (!player_nb)
	{
		corewar_usage();
		corewar_quit("\nNeed at least one champion to start game");
	}
	cor->nb_players = player_nb;
	return (1);
}

int		cor_file(char *av)
{
	int i;

	i = ft_strlen(av);
	if (i <= 4)
		return (-1);
	i -= 4;
	if (ft_strncmp(&av[i], ".cor", 4))
	{
		ft_printf("NOT .cor\n");
		return (-1);
	}
	else
	{
		ft_printf("IS .cor\n");
		return (1);
	}
}

void		get_champion(t_corewar *cor, char **av, int i, int *player_nb)
{
	if (*player_nb <= MAX_PLAYERS)
	{
		read_process(av[i], cor, *player_nb);
		if (DEBUG)
			print_process_data(cor, *player_nb);
		(*player_nb)++;
	}
	else
		corewar_quit("\t=> Too many champions (maximum 4)");
}

// fonction doublons, deja presente dans asm


uint32_t	swap_endian(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}
