#include "vm.h"

// ldi | Indirect Load | 0x0A
// Usage : ldi S(RG/ID/D2), S(ID/D2), D(RG) Durée : 25
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Non
// Transfert indirect RAM > Registre. Charge la valeur a l'adresse
// resultante de l'addition des deux premiers paramametres, dans le
// registre passé en troisieme parametre.

static int			ft_fill_value(t_corewar *cor, t_plst *plst, t_arg *arg)
{
	unsigned int	j;
	int				result;

	result = 0;
	j = 0;
	while (j < REG_SIZE)
	{	
		result = (result << 8);
		result += cor->arena[pc_modulo(plst->p.og_pc + ft_get_restricted_addr(arg->value[0] + arg->value[1]) + j)];
		j++;
	}
	return (result);
}

void	inst_ldi(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "LDI", 0);
	ft_arg_init(&arg, 3, HALF, TRUE);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] == 0 || ft_check_arg_type(arg, 1, REG_CODE, DIR_CODE) == FAIL
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
	ft_get_reg_value(&arg, plst, FRST | SCND);
	plst->p.reg[arg.value[2]] = ft_fill_value(cor, plst, &arg);
	//plst->p.carry = !(plst->p.reg[arg.value[2]]);
	ft_print_debug(plst, "LDI", 1);
}
