#include "vm.h"

// st | Direct Store | 0x03
// Usage : st S(RG), D(RG/ID) Durée : 5
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Non
// Transfert direct Registre > RAM / Registre. Charge le contenu du
// registre passé en premier parametre dans le second parametre.

void		fill_value(t_corewar *cor, t_plst *plst, t_arg arg)
{
	if (arg.type[1] == REG_CODE)
		plst->p.reg[arg.value[1]] = arg.value[0];
	else
		print_value(cor, arg.value[0], plst->p.og_pc
			+ ft_get_restricted_addr(arg.value[1], FULL), plst);
}

void		inst_st(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "ST", 0);
	ft_arg_init(&arg, 2, HALF, TRUE, NORMAL);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] != REG_CODE
		|| ft_check_arg_type(arg, 1, IND_CODE, REG_CODE) == FAIL)
	{
		pc_modulo2(plst, ft_get_args_size_sum(arg));
		ft_verbosity_instru(cor, plst, arg, FAIL);
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(cor, plst, arg) == FAIL)
		return ;
	ft_verbosity_instru(cor, plst, arg, SUCCESS);
	ft_get_reg_value(&arg, plst, FRST);
	fill_value(cor, plst, arg);
	ft_print_debug(plst, "ST", 1);
}
