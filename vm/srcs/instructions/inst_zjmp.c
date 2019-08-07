#include "../../includes/vm.h"

void	inst_zjmp(t_corewar *cor, int i)
{
	// (void)cor;
	ft_printf("process[%d] : ZJMP\n", i);
	int pc;

	if (cor->process[i].carry == 1)
	{
		pc = (cor->process[i].pc + 2) % MEM_SIZE;
		//PC = ( PC + ( param % IDXMOD ) ) % MEMSIZE
		cor->process[i].pc = pc;
	}
}
