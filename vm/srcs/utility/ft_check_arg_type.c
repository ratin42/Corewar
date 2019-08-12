#include "../../includes/vm.h"

int		ft_check_arg_type(t_arg arg, int i, int code1, int code2)
{
	if (arg.type[i] == code1 || arg.type[i] == code2)
		return (SUCCESS);
	else
		return (FAIL);
}
