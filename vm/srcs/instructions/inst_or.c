#include "../../includes/vm.h"

// or | Logical OR | 0x07
// Usage : or S(RG/ID/D4), S(RG/ID/D4), D(RG) Durée : 6
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Effectue un OR logique entre les deux premiers paramametres et
// stock le resultat dans le troisieme paramametre. Si la valeur resultante
// est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.

void	inst_or(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : OR\n", i);
}
