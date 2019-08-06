#include "../../includes/vm.h"

void	update_pc(t_corewar *cor, int i)
{
	int	arg;
	int pc;

	pc = cor->process[i].pc;
	arg = cor->instru.nbr_of_param;
	if (arg >= 1)
		pc += cor->instru.type_of_param.param1;
	if (arg >= 2)
		pc += cor->instru.type_of_param.param2;
	if (arg == 3)
		pc += cor->instru.type_of_param.param3;
	cor->process[i].pc = pc;
}
