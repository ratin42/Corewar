#include "../../includes/vm.h"

// xor | Logical XOR | 0x08
// Usage : xor S(RG/ID/D4), S(RG/ID/D4), D(RG) Durée : 6
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Effectue un XOR logique entre les deux premiers paramametres et
// stock le resultat dans le troisieme paramametre. Si la valeur resultante
// est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.

void	inst_xor(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : XOR\n", i);
}
