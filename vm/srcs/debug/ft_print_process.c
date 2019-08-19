#include "vm.h"

void	ft_print_debug(t_plst *plst, char *op_name, int end)
{
	if (DEBUG)
	{
		if (end == 0)
			printf("##################  %s  ##################\n", op_name);
		printf("%s\n", end ? "\nAFTER\n" : "BEFORE\n");
		ft_print_process(plst->p);
		if (end == 1)
			printf("##################  END  ##################\n");
	}
}
void	ft_print_process(t_process p)
{
	int		i;

	i = 1;
	printf("Name: %-*s\n", PROG_NAME_LENGTH, p.name);
	printf("ID: %d\n", p.id);
	printf("PC: %u\n", p.pc);
	printf("OG_PC: %u\n", p.og_pc);
	printf("Carry: %u\n", p.carry);
	printf("live: %u\n", p.live);
	printf("No_live: %d\n", p.no_live);
	printf("Wait: %d\n", p.wait);
	printf("Op code: %d\n", p.opcode);
	printf("REG\n");
	while (i <= REG_NUMBER)
	{
		printf("[%d]: %d\n", i, p.reg[i]);
		i++;
	}
}

void	ft_print_plst(t_plst *plst)
{
	while (plst != NULL)
	{
		ft_print_process(plst->p);
		plst = plst->next;
	}
}