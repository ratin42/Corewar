
#include "vm.h"

int		get_reg_value(t_corewar *cor, t_plst *plst)
{
	int	reg_index;

	reg_index = get_reg_index(cor, plst);
	if (check_registre_index(reg_index, 1, 1) == 0)
		return (1);
	return (plst->p.reg[reg_index]);
}

int		get_small_dir(t_corewar *cor, t_plst *plst)
{
	int	direct;

	direct = cor->arena[plst->p.pc];
	direct = direct << 2;
	plst->p.pc =  pc_modulo(plst->p.pc + 1);
	direct = cor->arena[plst->p.pc];
	plst->p.pc =  pc_modulo(plst->p.pc + 1);
	return (direct);
}

int		get_ind(t_corewar *cor, t_plst *plst)
{
	int	addr;
	int	pc;

	pc = plst->p.pc;
	addr = get_small_dir(cor, plst);
	return (cor->arena[ft_get_restricted_addr(pc + addr)]);
}
