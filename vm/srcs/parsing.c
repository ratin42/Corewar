#include "../includes/vm.h"

int		parse_arguments(int ac, char **av, t_corewar *cor)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-d"))
			dump_option(cor, av, &i);
		else if (!ft_strcmp(av[i], "-v"))
			verbosity_option(cor, av, &i);
		else if (!ft_strcmp(av[i], "-n"))
			order_option(cor, av, &i);
		else if (cor_file(av[i]) == 1)
			get_champion(cor, av, i);
		else
		{
			corewar_usage();
			corewar_quit("");
		}
	}
	if (!cor->nb_players)
	{
		corewar_usage();
		corewar_quit("\nNeed at least one champion to start game");
	}
	if (cor->order_option)
		order_process(cor);
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

void	order_process(t_corewar *cor)
{
	int i;
	int j;

	if (!check_doubles_order(cor))
		corewar_quit("Cannot give multiple same [number] with -n option");
	adjust_order(cor);
	i = -1;
	while (++i < cor->nb_players)
	{
		j = i;
		while (++j < cor->nb_players)
		{
			if (cor->process[i].order != -1 && cor->process[i].order > cor->process[j].order)
				swap_process(cor, i, j);
		}
	}
}