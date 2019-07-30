#include "../includes/vm.h"

int		parse_arguments(char *av)
{
	int i;

	i = ft_strlen(av);
	if (i <= 4)
		return (-1);
	i -= 4;
	if (ft_strncmp(&av[i], ".cor", 4))
		return (-1);
	else
		return (1);
}

int		get_infos(int ac, char **av, t_corewar *cor)
{
	int i;
	int player_nb;

	player_nb = 0;
	i = 0;
	while (++i < ac)
	{
		if (parse_arguments(av[i]) == -1)
		{
			if (DEBUG)
				printf("[%s]\t--> Not a valid .cor file\n", av[i]);
			return (-1);
			player_nb++;
		}
		if (player_nb <= MAX_PLAYERS)
		{
			read_process(av[i], cor, player_nb);
			if (DEBUG)
				print_process_data(cor, player_nb);
		}
		else
			corewar_quit("\t=> Too many champions (maximum 4)");
	}
	return (1);
}

// fonction doublons, deja presente dans asm


uint32_t	swap_endian(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}
