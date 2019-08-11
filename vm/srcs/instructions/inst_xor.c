#include "../../includes/vm.h"

// xor | Logical XOR | 0x08
// Usage : xor S(RG/ID/D4), S(RG/ID/D4), D(RG) Durée : 6
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Effectue un XOR logique entre les deux premiers paramametres et
// stock le resultat dans le troisieme paramametre. Si la valeur resultante
// est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.

void	inst_xor(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	//ft_printf("process[%d] : XOR\n", i);

	arg.nb_arg = 3;
	arg.dir_size = FULL;
	ft_get_opcode(cor, plst->p.pc, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] == 0 || arg.type[1] == 0 || arg.type[2] != REG_CODE)
	{
		ft_printf("OCP error.\n");
		pc_modulo2(plst, 1);
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(arg) == FAIL)
	{
		ft_printf("Register argument is not within the valid range.\n");
		return ;
	}
	plst->p.reg[arg.value[2]] = arg.value[0] & arg.value[1];
	plst->p.carry = !(arg.value[0] ^ arg.value[1]);
}