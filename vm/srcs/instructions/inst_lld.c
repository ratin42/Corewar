#include "../../includes/vm.h"

// lld | Long Direct Load | 0x0D
// Usage : lld S(ID/D4), D(RG) Durée : 10
// OCP : Oui Adressage Restreint : Non Modifie le carry : Oui
// Identique a Direct Load mais sans restriction de l'adressage.

void	inst_lld(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : LLD\n", i);
}
