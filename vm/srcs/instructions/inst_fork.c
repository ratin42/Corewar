#include "../../includes/vm.h"

void	inst_fork(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : FORK\n", i);
}
