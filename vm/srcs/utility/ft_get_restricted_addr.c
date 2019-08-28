#include "vm.h"

int		ft_get_restricted_addr(int value)
{
	short	ret;

	if (value < 0)
		return (value % IDX_MOD);
	ret = (short)value;
	ret %= IDX_MOD;
	return (ret);
}
