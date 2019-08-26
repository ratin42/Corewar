#include "vm.h"

void	pc_modulo2(t_plst *plst, int i)
{
	plst->p.pc = pc_modulo(plst->p.pc + i);
}

int		pc_modulo(int pc)
{
	if (pc < 0)
	{
		while (pc < 0)
			pc += MEM_SIZE;
	}
	else if (pc >= MEM_SIZE)
	{
		while (pc >= MEM_SIZE)
			pc -= MEM_SIZE;
	}
	return (pc);
}
