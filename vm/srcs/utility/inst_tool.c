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

	reg = cor->arena[plst->p.pc];
	plst->p.pc = pc_modulo(plst->p.pc + 1);
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
	plst->p.pc =  pc_modulo(plst->p.pc + 1);
	return (type_param);
}

int	check_registre_index(int reg_1, int reg_2, int reg_3, t_plst *plst)
{
	if (reg_1 < 1 || reg_1 > 16)
	{
		ft_printf("Reg_1: %d not valid for process[%d]\n", reg_1, plst->p.id);
		return (0);
	}
	if (reg_2 < 1 || reg_2 > 16)
	{
		ft_printf("Reg_2: %d not valid for process[%d]\n", reg_2, plst->p.id);
		return (0);
	}
	if (reg_3 < 1 || reg_3 > 16)
	{
		ft_printf("Reg_3: %d not valid for process[%d]\n", reg_3, plst->p.id);
		return (0);
	}
	return (1);
}
