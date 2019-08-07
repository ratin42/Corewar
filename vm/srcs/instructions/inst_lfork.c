#include "../../includes/vm.h"

// lfork | Long Fork | 0x0F
// Usage : lfork S(D2) Durée : 1000
// OCP : Non Adressage Restreint : Non Modifie le carry : Non
// Identique a Fork mais sans restriction de l'adressage.

void	inst_lfork(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : LFORK\n", i);
}
