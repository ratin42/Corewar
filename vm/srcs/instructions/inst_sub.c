
#include "vm.h"

void	inst_sub(t_corewar *cor, t_plst *plst)
{
	int reg[3];
	int	*type_param;

	ft_print_debug(plst, "SUB", 0);
	type_param = check_opcode(cor, plst);
	reg[0] = get_reg_index(cor, plst);
	reg[1] = get_reg_index(cor, plst);
	reg[2] = get_reg_index(cor, plst);
	if (type_param[0] != REG_CODE || type_param[1] != REG_CODE || type_param[2]
		!= REG_CODE)
	{
		if (!cor->visu && cor->verbosity)
			ft_printf("sub error.\n");
		free(type_param);
		return ;
	}
	if (!check_registre_index(reg[0], reg[1], reg[2]))
	{
		free(type_param);
		return ;
	}
	plst->p.reg[reg[2]] = plst->p.reg[reg[0]] - plst->p.reg[reg[1]];
	plst->p.carry = (plst->p.reg[reg[2]] == 0);
	ft_print_debug(plst, "SUB", 1);
}
