#include "vm.h"

// ld | Direct Load | 0x02
// Usage : ld S(ID/D4), D(RG) Durée : 5
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert direct RAM > Registre. Charge le premier parametre dans le
// registre passé en second parametre. Si la valeur du premier
// parametre est egale a zero, alors le carry passe a l'etat un, sinon a
// l'etat zero.

void	inst_ld(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "LD", 0);
	ft_arg_init(&arg, 2, FULL, TRUE, NORMAL);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (ft_check_arg_type(arg, 0, IND_CODE, DIR_CODE) == FAIL
			|| arg.type[1] != REG_CODE)
	{
		pc_modulo2(plst, ft_get_args_size_sum(arg));
		ft_verbosity_adv(cor, plst);
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(cor, plst, arg) == FAIL)
		return ;
	ft_verbosity_instru(cor, plst, arg);
	plst->p.reg[arg.value[1]] = arg.value[0];
	plst->p.carry = !(arg.value[0]);
	ft_verbosity_adv(cor, plst);
	ft_print_debug(plst, "LD", 1);
}
