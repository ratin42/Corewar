#include "../../includes/vm.h"

int   pc_modulo(int pc)
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

int     get_reg_index(t_corewar *cor, t_plst *plst)
{
	int reg;

	plst->p.pc = pc_modulo(plst->p.pc + 1);
	reg = cor->arena[plst->p.pc];
	return (reg);
}

int		*check_opcode(t_corewar *cor, t_plst *plst)
{
	int	param1;
	int	param2;
	int	param3;
	int	*type_param;

	type_param = malloc(sizeof(int) * 3);
	param1 = ((cor->arena[plst->p.pc] >> 6) & 0x3);
	type_param[0] = param1;
	param2 = ((cor->arena[plst->p.pc] >> 4) & 0x3);
	type_param[1] = param2;
	param3 = ((cor->arena[plst->p.pc] >> 2) & 0x3);
	type_param[2] = param3;
	return (type_param);
}

