#include "vm.h"

int		ft_get_restricted_addr(int value)
{
	value %= MEM_SIZE;
	if (value >= MEM_SIZE - IDX_MOD)
		return (value);
	else
		return (value % IDX_MOD);
}
