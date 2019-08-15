
#include "../../includes/vm.h"

void	inst_sub(t_corewar *cor, t_plst *plst)
{
	// if (DEBUG)
	// 	ft_printf("SUB\n");
	ft_print_debug(plst, "SUB", 0);
	int reg_1;
	int reg_2;
	int reg_3;
	int	*type_param;

	type_param = check_opcode(cor, plst);
	reg_1 = get_reg_index(cor, plst);
	reg_2 = get_reg_index(cor, plst);
	reg_3 = get_reg_index(cor, plst);
	if (type_param[0] != REG_CODE || type_param[1] != REG_CODE || type_param[2]
		!= REG_CODE)
	{
		if (!cor->visu && cor->verbosity)
			ft_printf("sub error.\n");
		return ;
	}
	if (!check_registre_index(reg_1, reg_2, reg_3))
		return ;
	plst->p.reg[reg_3] = plst->p.reg[reg_1] - plst->p.reg[reg_2];
	plst->p.carry = (plst->p.reg[reg_3] == 0);
	ft_print_debug(plst, "SUB", 1);
}