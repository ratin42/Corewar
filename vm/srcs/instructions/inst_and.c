#include "../../includes/vm.h"

// and | Logical AND | 0x06
// Usage : and S(RG/ID/D4), S(RG/ID/D4), D(RG) Durée : 6
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Effectue un AND logique entre les deux premiers paramametres et
// stock le resultat dans le troisieme paramametre. Si la valeur resultante
// est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.

void	inst_and(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : AND\n", i);
}
