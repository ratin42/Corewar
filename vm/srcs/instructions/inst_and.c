#include "../../includes/vm.h"

// and | Logical AND | 0x06
// Usage : and S(RG/ID/D4), S(RG/ID/D4), D(RG) Durée : 6
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Effectue un AND logique entre les deux premiers paramametres et
// stock le resultat dans le troisieme paramametre. Si la valeur resultante
// est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.

void	inst_and(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	//ft_print_debug(plst, "AND", 0);
	ft_arg_init(&arg, 3, FULL, TRUE);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] == 0 || arg.type[1] == 0 || arg.type[2] != REG_CODE)
	{
		if (!cor->visu && cor->verbosity)
			ft_printf("OCP error.\n");
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(arg) == FAIL)
	{

		if (!cor->visu && cor->verbosity)
			ft_printf("Register argument is not within the valid range.\n");
		return ;
	}
	plst->p.reg[arg.value[2]] = arg.value[0] & arg.value[1];
	plst->p.carry = !(arg.value[0] & arg.value[1]);
	//ft_print_debug(plst, "AND", 1);
}
