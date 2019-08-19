#include "vm.h"

void	ft_arg_init(t_arg *arg, int nb_arg, int dir_size, int addr_restrict)
{
	arg->nb_arg = nb_arg;
	arg->dir_size = dir_size;
	arg->addr_restrict = addr_restrict;
}
