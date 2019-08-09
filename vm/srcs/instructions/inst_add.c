
#include "../../includes/vm.h"

static int	check_registre(int reg_1, int reg_2, int reg_3, t_plst *plst)
{
	if (reg_1 < 1 || reg_1 > 16)
	{
		ft_printf("Reg_1: %d not valid for process[%d]\n", reg_1, plst->p.id);
		return (1);
	}
	if (reg_2 < 1 || reg_2 > 16)
	{
		ft_printf("Reg_2: %d not valid for process[%d]\n", reg_2, plst->p.id);
		return (1);
	}
	if (reg_3 < 1 || reg_3 > 16)
	{
		ft_printf("Reg_3: %d not valid for process[%d]\n", reg_3, plst->p.id);
		return (1);
	}
	return (0);
}

void	inst_add(t_corewar *cor, t_plst *plst)
{
	int reg_1;
	int reg_2;
	int reg_3;

	//debug
	ft_printf("process[%d] : funct: ADD\n", plst->p.id);

	//saute l'OCP
	plst->p.pc = pc_modulo(plst->p.pc + 1);

	//recupere les index des registres et avance le pc
	reg_1 = get_reg_index(cor, plst);
	reg_2 = get_reg_index(cor, plst);
	reg_3 = get_reg_index(cor, plst);

	//Replace le pc sur l'opcode suivant
	plst->p.pc = pc_modulo(plst->p.pc + 1);

	//verifie les index des registres
	if (check_registre(reg_1, reg_2, reg_3, plst))
		return ;

	//Ajoute le second parametre au premier parametre, et stock le
	//resultat dans le troisieme parametre
	plst->p.reg[reg_3] = plst->p.reg[reg_1] + plst->p.reg[reg_2];
	plst->p.carry = (plst->p.reg[reg_3] == 0);
}
