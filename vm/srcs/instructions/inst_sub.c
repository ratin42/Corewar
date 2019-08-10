#include "../../includes/vm.h"

void	inst_sub(t_corewar *cor, t_plst *plst)
{
	int reg_1;
	int reg_2;
	int reg_3;

	ft_printf("process[%d] : funct: SUB FINISHED\n", plst->p.id);

	//saute l'OCP
	plst->p.pc = pc_modulo(plst->p.pc + 1);

	//recupere les index des registres et avance le pc
	reg_1 = get_reg_index(cor, plst);
	reg_2 = get_reg_index(cor, plst);
	reg_3 = get_reg_index(cor, plst);

	//Replace le pc sur l'opcode suivant
	plst->p.pc = pc_modulo(plst->p.pc + 1);

	//verifie les index des registres
	if (check_registre_index(reg_1, reg_2, reg_3, plst))
		return ;

	//Ajoute le second parametre au premier parametre, et stock le
	//resultat dans le troisieme parametre
	plst->p.reg[reg_3] = plst->p.reg[reg_1] - plst->p.reg[reg_2];
	plst->p.carry = (plst->p.reg[reg_3] == 0);
}
