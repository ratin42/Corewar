#include "vm.h"

int		ft_get_restricted_addr(int value, int flag)
{
	short	ret;

	if (value < 0 || flag == FULL)
		return (value % IDX_MOD);
	ret = (short)value;
	ret %= IDX_MOD;
	return (ret);
}
