
#include "../../includes/vm.h"

void	inst_add(t_corewar *cor, t_plst *plst)
{
	int reg_1;
	int reg_2;
	int reg_3;

	//debug
	ft_printf("\nprocess[%d] : funct: ADD FINISHED\n", plst->p.id);

	//saute l'opcode et l'OCP
	plst->p.pc = pc_modulo(plst->p.pc + 2);

	//recupere les index des registres et avance le pc
	reg_1 = get_reg_index(cor, plst);
	reg_2 = get_reg_index(cor, plst);
	reg_3 = get_reg_index(cor, plst);


	//verifie les index des registres
	if (check_registre_index(reg_1, reg_2, reg_3, plst))
		return ;

	//Ajoute le second parametre au premier parametre, et stock le
	//resultat dans le troisieme parametre
	plst->p.reg[reg_3] = plst->p.reg[reg_1] + plst->p.reg[reg_2];
	plst->p.carry = (plst->p.reg[reg_3] == 0);
}
