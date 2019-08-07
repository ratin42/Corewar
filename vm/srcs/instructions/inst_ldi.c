#include "../../includes/vm.h"

// ldi | Indirect Load | 0x0A
// Usage : ldi S(RG/ID/D2), S(ID/D2), D(RG) Durée : 25
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert indirect RAM > Registre. Charge la valeur a l'adresse
// resultante de l'addition des deux premiers paramametres, dans le
// registre passé en troisieme parametre. Si cette valeur est nulle, alors le
// carry passe a l'etat un, sinon a l'ettat zero.

void	inst_ldi(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : LDI\n", i);
}
