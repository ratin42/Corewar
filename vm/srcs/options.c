#include "../includes/vm.h"

void	dump_option(t_corewar *cor, char **av, int *i)
{
	int		cycle;

	if (!av[*i + 1])
	{
		corewar_usage();
		corewar_quit("Need to specify N cycle with -d option");
	}
	(*i)++;
	cycle = ft_atoi(av[*i]);
	if (cycle < 0)
		cor->n_dump = -1;
	else
		cor->n_dump = cycle;
}
