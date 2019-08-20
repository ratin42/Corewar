#include "vm.h"

void	ft_get_opcode(t_corewar *cor, t_plst *plst, t_arg *arg)
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

static inline int		ft_get_arg_size(t_arg_type arg_type, int dir_size)
{
	if (arg_type == REG_CODE)
		return (1);
	if (arg_type == IND_CODE)
		return (IND_SIZE);
	if (arg_type == DIR_CODE)
		return (DIR_SIZE / dir_size);
	return (0);
}

void	ft_get_args_size(t_arg *arg)
{
	int		i;
	
	i = 0;
	while (i < arg->nb_arg)
	{
		arg->size[i] = ft_get_arg_size(arg->type[i], arg->dir_size);
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
