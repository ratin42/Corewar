#include "../includes/vm.h"

void	corewar_quit(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_SUCCESS);
}


int main(int ac, char **av)
{
	t_corewar	cor;

	if (ac <= 1)
		return (0);
	else
	{
		if (get_infos(ac, av, &cor) == -1)
		{
			if (DEBUG)
				printf("\nERROR get_infos == -1\n");
			return (0);
		}
	}
	return (1);
}
