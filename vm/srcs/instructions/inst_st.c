#include "../../includes/vm.h"

// st | Direct Store | 0x03
// Usage : st S(RG), D(RG/ID) Durée : 5
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert direct Registre > RAM / Registre. Charge le contenu du
// registre passé en premier parametre dans le second parametre. Si la
// valeur du premier parametre est egale a zero, alors le carry passe a
// l'etat un, sinon a l'etat zero.

void	inst_st(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : ST\n", i);
}
