#include "../../includes/vm.h"

// lfork | Long Fork | 0x0F
// Usage : lfork S(D2) Durée : 1000
// OCP : Non Adressage Restreint : Non Modifie le carry : Non
// Identique a Fork mais sans restriction de l'adressage.

void	inst_lfork(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;
	t_plst	*elem;

	ft_arg_init(&arg, 1, HALF, TRUE);
	arg.type[0] = DIR_CODE;
	arg.size[0] = 2;
	ft_get_args(cor, plst, &arg);
	if (!(elem = malloc(sizeof(t_plst))))
		return ;//voir si on met autre chose ou pas
	ft_memcpy(elem, plst, sizeof(t_plst));
	elem->p.pc = pc_modulo(plst->p.pc + arg.value[0]);
	elem->next = cor->plst;
	cor->plst = elem;
}
