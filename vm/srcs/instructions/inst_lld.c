#include "vm.h"

// lld | Long Direct Load | 0x0D
// Usage : lld S(ID/D4), D(RG) Durée : 10
// OCP : Oui Adressage Restreint : Non Modifie le carry : Oui
// Identique a Direct Load mais sans restriction de l'adressage.

void	inst_lld(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "LLD", 0);
	ft_arg_init(&arg, 2, FULL, FALSE);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (ft_check_arg_type(arg, 0, IND_CODE, DIR_CODE) == FAIL
			|| arg.type[1] != REG_CODE)
	{
		if (!cor->visu && cor->verbosity)
			ft_printf("OCP error.\n");
		pc_modulo2(plst, 1);
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(arg) == FAIL)
	{
		if (!cor->visu && cor->verbosity)
			ft_printf("Register argument is not within the valid range.\n");
		return ;
	}
	plst->p.reg[arg.value[1]] = arg.value[0];
	plst->p.carry = !(arg.value[0]);
	ft_print_debug(plst, "LLD", 1);
}
