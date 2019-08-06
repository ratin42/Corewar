#include "../../includes/vm.h"

void	inst_live(t_corewar *cor, int i)
{
	ft_printf("process[%d] : LIVE\n", i);
	cor->instru.nbr_of_param = 1;
	if (is_direct(cor->instru.type_of_param.param1) == T_DIR)
		cor->instru.type_of_param.param1 = DIR_SIZE;
 	if (cor->instru.type_of_param.param1 == DIR_SIZE)
    {
        ft_printf("le joueur %d(%s) est en vie\n", i, cor->process[i].name);
        cor->process[i].live = 1;
        cor->last_live_id = i;
        cor->last_live_name = cor->process[i].name;
        cor->current_live += 1;
		update_pc(cor, i);
    }
}
