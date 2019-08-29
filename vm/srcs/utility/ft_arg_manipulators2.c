#include "vm.h"

void				ft_get_opcode(t_corewar *cor, t_plst *plst, t_arg *arg)
{
	unsigned char	bmask;
	unsigned int	pc;

	bmask = 3;
	pc = plst->p.pc;
	arg->type[0] = ((bmask << 6) & cor->arena[pc]) >> 6;
	arg->type[1] = ((bmask << 4) & cor->arena[pc]) >> 4;
	arg->type[2] = ((bmask << 2) & cor->arena[pc]) >> 2;
	arg->type[3] = bmask & cor->arena[pc];
	pc_modulo2(plst, 1);
}

int					ft_get_args_size_sum(t_arg	arg)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (i < arg.nb_arg)
	{
		sum += arg.size[i];
		i++;
	}
	return (sum);
}

static inline int	ft_get_arg_size(t_arg_type arg_type, int dir_size)
{
	if (arg_type == REG_CODE)
		return (1);
	if (arg_type == IND_CODE)
		return (IND_SIZE);
	if (arg_type == DIR_CODE)
		return (DIR_SIZE / dir_size);
	return (0);
}

void				ft_get_args_size(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->nb_arg)
	{
		arg->size[i] = ft_get_arg_size(arg->type[i], arg->dir_size);
		i++;
	}
}

void				ft_arg_init(t_arg *arg, int nb_arg, int dir_size,
		int addr_restrict, int verbo)
{
	arg->nb_arg = nb_arg;
	arg->dir_size = dir_size;
	arg->addr_restrict = addr_restrict;
	arg->verbo = verbo;
}
