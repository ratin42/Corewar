#include "../../includes/vm.h"

// lldi | Long Indirect Load | 0x0E
// Usage : lldi S(RG/ID/D2), S(ID/D2), D(RG) Durée : 50
// OCP : Oui Adressage Restreint : Non Modifie le carry : Oui
// Identique a Indirect Load mais sans restriction de l'adressage.

void	inst_lldi(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : LLDI\n", i);
}
