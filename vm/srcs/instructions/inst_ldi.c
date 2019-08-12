#include "../../includes/vm.h"

// ldi | Indirect Load | 0x0A
// Usage : ldi S(RG/ID/D2), S(ID/D2), D(RG) Durée : 25
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert indirect RAM > Registre. Charge la valeur a l'adresse
// resultante de l'addition des deux premiers paramametres, dans le
// registre passé en troisieme parametre. Si cette valeur est nulle, alors le
// carry passe a l'etat un, sinon a l'ettat zero.

void	inst_ldi(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_arg_init(&arg, 3, HALF, TRUE);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] == 0 || ft_check_arg_type(arg, 1, IND_CODE, DIR_CODE) == FAIL
			|| arg.type[2] != REG_CODE)
	{
		ft_printf("OCP error.\n");
		pc_modulo2(plst, 1);//ou autre mouvement
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(arg) == FAIL)
	{
		ft_printf("Register argument is not within the valid range.\n");
		return ;
	}
	plst->p.reg[arg.value[2]] = cor->arena[pc_modulo(plst->p.pc
		+ ft_get_restricted_addr(arg.value[0] + arg.value[1]))];
	plst->p.carry = !((arg.value[0] + arg.value[1]) % IDX_MOD == 0);
}
