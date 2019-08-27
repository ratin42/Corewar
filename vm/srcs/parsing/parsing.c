#include "vm.h"

void		parse_arguments_2(t_corewar *cor)
{
	if (!cor->nb_players)
	{
		corewar_usage();
		corewar_quit("\nNeed at least one champion to start game");
	}
	if (cor->order_option)
		order_process(cor);
}

void		parse_arguments(int ac, char **av, t_corewar *cor)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-dump"))
			dump_option(cor, av, &i);
		else if (!ft_strcmp(av[i], "-v"))
			verbosity_option(cor, av, ac, &i);
		else if (!ft_strcmp(av[i], "-n"))
			order_option(cor, av, &i);
		else if (!ft_strcmp(av[i], "-visu"))
			cor->visu = 1;
		else if (!ft_strcmp(av[i], "--stealth"))
			cor->stealth = 1;
		else if (cor_file(av[i]) == 1)
			get_champion(cor, av, i);
		else
		{
			corewar_usage();
			corewar_quit("");
		}
	}
	parse_arguments_2(cor);
}

int			cor_file(char *av)
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

void		get_champion(t_corewar *cor, char **av, int i)
{
	if (cor->nb_players < MAX_PLAYERS)
	{
		read_process(av[i], cor, cor->nb_players);
		if (DEBUG)
			print_process_data(cor, cor->nb_players);
		cor->nb_players++;
	}
	else
		corewar_quit("\t=> Too many champions (maximum 4)");
}

void		order_process(t_corewar *cor)
{
	if (!check_doubles_order(cor))
		corewar_quit("Cannot give multiple same [number] with -n option");
	attribute_order(cor);
	reorder_process(cor);
}
