#include "vm.h"

void	inst_add(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "ADD", 0);
	ft_arg_init(&arg, 3, FULL, TRUE, NORMAL);
	ft_get_opcode(cor, plst, &arg);
	ft_get_args_size(&arg);
	if (arg.type[0] != REG_CODE || arg.type[1] != REG_CODE
			|| arg.typem[2] != REG_CODE)
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
	ft_verbosity_instru(cor, plst, arg);
	ft_get_reg_value(&arg, plst, FRST | SCND);
	plst->p.reg[arg.value[2]] = arg.value[0] + arg.value[1];
	plst->p.carry = (plst->p.reg[arg.value[2]] == 0);
	ft_print_debug(plst, "ADD", 1);
}
