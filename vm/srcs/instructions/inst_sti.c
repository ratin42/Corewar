
#include "vm.h"

// sti | Indirect Store | 0x0B
// Usage : sti S(RG), S(RG/ID/D2), S(RG/D2) Durée : 25
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert indirect Registre > RAM. Charge la valeur contenu dans le
// registre passé en premier parametre a l'adresse resultante de
// l'addition des deux derniers paramametres. Si cette valeur est nulle,
// alors le carry passe a l'etat un, sinon a l'ettat zero.

void	print_value(t_corewar *cor, int value, int addr, t_plst *plst)
{
	char	c;
	int		i;

	i = 0;
	addr = pc_modulo(addr);
	while (i < 4)
	{
		c = (value >> (8 * (3 - i))) & 0xFF;
		cor->arena[addr] = c;
		cor->render.bold[addr] = 50;
		cor->render.mem_owner[addr] = re_adjust_id(plst->p.id, &plst->p) + 1;
		addr = pc_modulo(addr + 1);
		i++;
	}
}

void	inst_sti(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "STI", 0);
	ft_arg_init(&arg, 3, HALF, TRUE, INDIRECT);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] != REG_CODE || arg.type[1] == 0
		|| ft_check_arg_type(arg, 2, DIR_CODE, REG_CODE) == FAIL)
	{
		pc_modulo2(plst, ft_get_args_size_sum(arg));
		ft_verbosity_instru(cor, plst, arg, FAIL);
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(cor, plst, arg) == FAIL)
		return ;
	ft_get_reg_value(&arg, plst, SCND | THRD);
	ft_verbosity_instru(cor, plst, arg, SUCCESS);
	print_value(cor, arg.value[0],
			plst->p.og_pc + ft_get_restricted_addr(arg.value[1] + arg.value[2], FULL), plst);
	ft_print_debug(plst, "STI", 1);
}
