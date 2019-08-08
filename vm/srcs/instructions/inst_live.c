#include "../../includes/vm.h"

void	inst_live(t_corewar *cor, int i)
{
	ft_printf("process[%d] : LIVE\n", i);
	cor->instru.nbr_of_param = 1;
	//if (is_direct(cor->instru.type_of_param.param1) == T_DIR)
		cor->instru.type_of_param.param1 = DIR_SIZE;
 	if (cor->instru.type_of_param.param1 == DIR_SIZE)
    {
        if (cor->verbosity)
            ft_printf("un processus dit que le joueur %d(%s) est en vie\n", i + 1, cor->process[i].name);
        cor->process[i].live += 1;
        cor->last_live_id = i;
		//update_pc(cor, i);
        cor->live_declared += 1;
        cor->process[i].no_live = 0;
        cor->process[i].pc = (cor->process[i].pc + 5) % MEM_SIZE;
        //cor->process[i].pc = pc_modulo((cor->process[i].pc + 5) % MEM_SIZE);
    }
}
