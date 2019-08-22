#include "vm.h"

void	ft_get_reg_value(t_arg *arg, t_plst *plst, int pos)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	while (i < arg->nb_arg)
	{
		if (pos & flag && arg->type[i] == REG_CODE)
			arg->value[i] = plst->p.reg[arg->value[i]];
		flag = flag << 1;
		i++;
	}
} 

static inline void	ft_get_ind(t_corewar *cor, t_plst *plst,
t_arg *arg, int i)
{
	unsigned int	j;
	int				pos;

	j = 0;
	pos = arg->addr_restrict == 1
			? ft_get_restricted_addr(arg->value[i])
			: pc_modulo(arg->value[i]);
	arg->value[i] = 0;
	while (j < 4)
	{
		arg->value[i] = (arg->value[i] << 8);
		arg->value[i] += cor->arena[pc_modulo(plst->p.og_pc + pos + j)];
		j++;
	}
}

static inline void	ft_get_arg(t_corewar *cor, t_plst *plst,
t_arg *arg, int i)
{
	unsigned int	j;

	j = 0;
	arg->value[i] = 0;
	while (j < arg->size[i])
	{	
		arg->value[i] = (arg->value[i] << 8);
		arg->value[i] += cor->arena[plst->p.pc];
		pc_modulo2(plst, 1);
		j++;
	}
	if (arg->type[i] == IND_CODE)
		ft_get_ind(cor, plst, arg, i);
}

void	ft_get_args(t_corewar *cor, t_plst *plst, t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->nb_arg)
	{
		ft_get_arg(cor, plst, arg, i);
		i++;
	}
}
