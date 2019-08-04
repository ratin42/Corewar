#include "../includes/vm.h"

void	dump_option(t_corewar *cor, char **av, int *i)
{
	int		cycle;

	if (!av[*i + 1])
	{
		corewar_usage();
		corewar_quit("Need to specify N cycle after -d option");
	}
	(*i)++;
	cycle = ft_atoi(av[*i]);
	if (cycle < 0)
		cor->n_dump = -1;
	else
		cor->n_dump = cycle;
}

void	verbosity_option(t_corewar *cor, char **av, int *i)
{
	//Ca vous semble necessaire de faire plusieurs types ?
	
	(void)av;
	(void)i;

	cor->verbosity = 1;
}

void	order_option(t_corewar *cor, char **av, int *i)
{
	int	order;

	if (!av[*i + 1])
	{
		corewar_usage();
		corewar_quit("Need to specify [number] after -n option");
	}
	(*i)++;
	order = ft_atoi(av[*i]);
	if (order < 1 || order > MAX_PLAYERS)
	{
		corewar_usage();
		corewar_quit("-n [number] option has to be between 1 and 4 (included)");
	}
	else
	{
		cor->order = order;
		cor->order_option = 1;
	}
}
