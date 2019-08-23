#include "vm.h"

int		ft_get_restricted_addr(int value)
{
	short	ret;

	ret = (short)value;
	ret %= IDX_MOD;
	return (ret);
}
