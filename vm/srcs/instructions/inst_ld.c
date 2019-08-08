#include "../../includes/vm.h"

// ld | Direct Load | 0x02
// Usage : ld S(ID/D4), D(RG) Durée : 5
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert direct RAM > Registre. Charge le premier parametre dans le
// registre passé en second parametre. Si la valeur du premier
// parametre est egale a zero, alors le carry passe a l'etat un, sinon a
// l'etat zero.

void	inst_ld(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : LD\n", i);
}


