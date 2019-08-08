#include "../../includes/vm.h"

void	inst_add(t_corewar *cor, int i)
{
	int reg_1;
	int reg_2;
	int reg_3;

	ft_printf("process[%d] : funct: ADD\n", i);
	cor->process[i].pc = pc_modulo(cor->process[i].pc + 1);
	reg_1 = get_reg(cor, i);
	reg_2 = get_reg(cor, i);
	reg_3 = get_reg(cor, i);

	//comment gerer ce cas d'erreur?
	if (reg_1 < 1 || reg_1 > 16)
		ft_printf("Reg_1: %d not valid, process[%d]\n", reg_1, i);
	if (reg_2 < 1 || reg_2 > 16)
		ft_printf("Reg_2: %d not valid, process[%d]\n", reg_2, i);
	if (reg_3 < 1 || reg_3 > 16)
		ft_printf("Reg_3: %d not valid, process[%d]\n", reg_3, i);

	cor->process[i].reg[reg_3] = cor->process[i].reg[reg_1]
		+ cor->process[i].reg[reg_2];
	cor->process[i].carry = (cor->process[i].reg[reg_3] == 0);
	cor->process[i].pc = pc_modulo(cor->process[i].pc + 1);
}
