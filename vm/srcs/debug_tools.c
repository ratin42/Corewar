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

const char *bit_rep[16] = {
    [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011",
    [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111",
    [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011",
    [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
};

void print_byte(uint8_t byte)
{
    ft_printf("%s%s", bit_rep[byte >> 4], bit_rep[byte & 0x0F]);
}
