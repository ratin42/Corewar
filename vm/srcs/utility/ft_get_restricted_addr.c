#include "vm.h"

int		ft_get_restricted_addr(int value)
{
	if (value >= 32768 && value % MEM_SIZE >= MEM_SIZE - IDX_MOD)
		return (value %= MEM_SIZE);
	else
		return (value % IDX_MOD);
}
