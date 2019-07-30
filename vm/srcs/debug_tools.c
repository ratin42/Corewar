#include "../includes/vm.h"

void	print_process_data(t_corewar *cor, int player_nb)
{
	printf("\n");

	printf("-> Player: [%d]\n\n", player_nb);
	printf("\t=>prog_name = [%s]\n", cor->process[player_nb].prog_name);
	printf("\t=>comment   = [%s]\n", cor->process[player_nb].comment);
	printf("\t=>prog_size = [%u]\n", cor->process[player_nb].prog_size);
	printf("\t=>magic     = [%u]\n", cor->process[player_nb].magic);

	printf("\n\n");
}
