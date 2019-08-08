#include "../../includes/vm.h"

int   pc_modulo(int pc)
{
	/*
	if (pc < 0)
	{
		pc += MEM_SIZE;
		return (pc % MEM_SIZE);
	}
	else if (pc >= MEM_SIZE)
	{
		pc -= MEM_SIZE;
	}
	*/
	return (pc);	
}

int     get_reg(t_corewar *cor, int i)
{
	int reg;

	cor->process[i].pc = pc_modulo(cor->process[i].pc + 1);
	//ft_printf("cor->process[i].pc = %d\n", cor->process[i].pc);
	reg = cor->arena[cor->process[i].pc];
	return (reg);
}
