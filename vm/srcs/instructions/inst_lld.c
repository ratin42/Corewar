#include "vm.h"

// lld | Long Direct Load | 0x0D
// Usage : lld S(ID/D4), D(RG) Durée : 10
// OCP : Oui Adressage Restreint : Non Modifie le carry : Oui
// Identique a Direct Load mais sans restriction de l'adressage.

void	inst_lld(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "LLD", 0);
	ft_arg_init(&arg, 2, FULL, FALSE, NORMAL);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (ft_check_arg_type(arg, 0, IND_CODE, DIR_CODE) == FAIL
			|| arg.type[1] != REG_CODE)
	{
		pc_modulo2(plst, ft_get_args_size_sum(arg));
		ft_verbosity_instru(cor, plst, arg, FAIL);
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(cor, plst, arg) == FAIL)
		return ;
	ft_verbosity_instru(cor, plst, arg, SUCCESS);
	plst->p.reg[arg.value[1]] = arg.type[0] == DIR_CODE
		? arg.value[0] : arg.value[0] >> 16;
	plst->p.carry = !(plst->p.reg[arg.value[1]]);
	ft_print_debug(plst, "LLD", 1);
}
