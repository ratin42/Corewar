#include "../includes/vm.h"

void	print_process_data(t_corewar *cor, int player_nb)
{
	unsigned int i;

	i = -1;
	ft_printf("\n\n");
	ft_printf("-------------------------------------------------------\n");
	ft_printf("-> Player: [%d]\n\n", player_nb);
	ft_printf("\t=>prog_name = [%s]\n", cor->process[player_nb].name);
	ft_printf("\t=>comment   = [%s]\n", cor->process[player_nb].comment);
	ft_printf("\t=>prog_size = [%u]\n", cor->process[player_nb].size);
	ft_printf("\t=>magic     = [%u]\n", cor->process[player_nb].magic);
	
	ft_printf("\t=>Code:     =\n\n");
	while (++i < cor->process[player_nb].size)
	{

		ft_printf("%02x", cor->process[player_nb].code[i]);
		if (i % 9 == 1)
			ft_printf("\n");
	}

	ft_printf("\n-------------------------------------------------------");
	ft_printf("\n\n\n");
}
