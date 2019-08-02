#include "../includes/vm.h"

//Connaitre le size min d'un champion pour rejeter comme zaz;

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
		//INIT ET BZERO;
		if (get_infos(ac, av, &cor) == -1)
		{
			if (DEBUG)
				ft_printf("\nERROR get_infos == -1\n");
			return (0);
		}
		print_process_data(&cor, 0);
		create_arena(&cor);

	}
	return (1);
}

void	create_arena(t_corewar *cor)
{
	int i;
	int p;
	int j = 0;

	i = -1;
	ft_bzero(cor->arena, MEM_SIZE);
	while (++i < cor->nb_players)
	{
		ft_memcpy((void*)&cor->arena + ((MEM_SIZE / cor->nb_players) * i),
				cor->process[i].code, cor->process[i].size);
	}

	p = 0;
	i = -1;

	while (++i < MEM_SIZE)
	{
		if (j == 64 || i == 0)
		{
			ft_putchar('\n');
			ft_printf("0x%.4x : ", p);
			p += 64;
			j = 0;
		}
		ft_printf("%.2x ", cor->arena[i]);
		j++;

	}
	ft_printf("\n");


}
