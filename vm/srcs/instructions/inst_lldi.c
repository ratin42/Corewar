#include "../../includes/vm.h"

// lldi | Long Indirect Load | 0x0E
// Usage : lldi S(RG/ID/D2), S(ID/D2), D(RG) Durée : 50
// OCP : Oui Adressage Restreint : Non Modifie le carry : Oui
// Identique a Indirect Load mais sans restriction de l'adressage.

void	inst_lldi(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "LLDI", 0);
	ft_arg_init(&arg, 3, HALF, FALSE);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] == 0 || ft_check_arg_type(arg, 1, IND_CODE, DIR_CODE) == FAIL
			|| arg.type[2] != REG_CODE)
	{
		if (!cor->visu && cor->verbosity)
			ft_printf("OCP error.\n");
		pc_modulo2(plst, 1);//ou autre mouvement
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(arg) == FAIL)
	{
		if (!cor->visu && cor->verbosity)
			ft_printf("Register argument is not within the valid range.\n");
		return ;
	}
	plst->p.reg[arg.value[2]] = cor->arena[pc_modulo(plst->p.og_pc
		+ arg.value[0] + arg.value[1])];
	plst->p.carry = !((arg.value[0] + arg.value[1]) % IDX_MOD == 0);
	ft_print_debug(plst, "LLDI", 1);
}
