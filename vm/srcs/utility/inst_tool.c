#include "vm.h"

int		get_reg_index(t_corewar *cor, t_plst *plst)
{
	int reg;

	reg = cor->arena[plst->p.pc];
	plst->p.pc = pc_modulo(plst->p.pc + 1);
	return (reg);
}

int		*check_opcode(t_corewar *cor, t_plst *plst)
{
	int	param1;
	int	param2;
	int	param3;
	int	*type_param;

	if (!(type_param = ft_memalloc(sizeof(int) * 3)))
		corewar_quit("malloc error in check_opcode\n");
	param1 = ((cor->arena[plst->p.pc] >> 6) & 0x3);
	type_param[0] = param1;
	param2 = ((cor->arena[plst->p.pc] >> 4) & 0x3);
	type_param[1] = param2;
	param3 = ((cor->arena[plst->p.pc] >> 2) & 0x3);
	type_param[2] = param3;
	plst->p.pc = pc_modulo(plst->p.pc + 1);
	return (type_param);
}

int		ft_check_reg_index(t_corewar *cor, t_plst *plst, t_arg arg)
{
	int		i;

	i = 0;
	while (i < arg.nb_arg)
	{
		if (arg.type[i] == REG_CODE
			&& (arg.value[i] < 1 || arg.value[i] > REG_NUMBER))
			{
				ft_verbosity_instru(cor, plst, arg, FAIL);
				return (FAIL);
			}
		i++;
	}
	return (SUCCESS);
}

int		check_registre_index(int reg_1, int reg_2, int reg_3)
{
	if (reg_1 < 1 || reg_1 > 16)
		return (0);
	if (reg_2 < 1 || reg_2 > 16)
		return (0);
	if (reg_3 < 1 || reg_3 > 16)
		return (0);
	return (1);
}
