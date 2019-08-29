#include "vm.h"

// lldi | Long Indirect Load | 0x0E
// Usage : lldi S(RG/ID/D2), S(ID/D2), D(RG) Durée : 50
// OCP : Oui Adressage Restreint : Non Modifie le carry : Oui
// Identique a Indirect Load mais sans restriction de l'adressage.

static inline int	ft_fill_value(t_corewar *cor, t_plst *plst, t_arg *arg)
{
	unsigned int	j;
	int				result;

	result = 0;
	j = 0;
	while (j < REG_SIZE)
	{
		result = (result << 8);
		result += cor->arena[pc_modulo(plst->p.og_pc
				+ arg->value[0] + arg->value[1] + j)];
		j++;
	}
	return (result);
}

void				inst_lldi(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "LLDI", 0);
	ft_arg_init(&arg, 3, HALF, FALSE, INDIRECT);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] == 0 || !ft_check_arg_type(arg, 1, REG_CODE, DIR_CODE)
			|| arg.type[2] != REG_CODE)
	{
		pc_modulo2(plst, ft_get_args_size_sum(arg));
		ft_verbosity_adv(cor, plst);
		return ;
	}
	ft_get_args(cor, plst, &arg);
	if (ft_check_reg_index(cor, plst, arg) == FAIL)
		return ;
	ft_get_reg_value(&arg, plst, FRST | SCND);
	ft_verbosity_instru(cor, plst, arg);
	plst->p.reg[arg.value[2]] = ft_fill_value(cor, plst, &arg);
	plst->p.carry = !(plst->p.reg[arg.value[2]]);
	ft_verbosity_adv(cor, plst);
	ft_print_debug(plst, "LLDI", 1);
}
