#include "../../includes/vm.h"

// sti | Indirect Store | 0x0B
// Usage : sti S(RG), S(RG/ID/D2), S(ID/D2) Durée : 25
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert indirect Registre > RAM. Charge la valeur contenu dans le
// registre passé en premier parametre a l'adresse resultante de
// l'addition des deux derniers paramametres. Si cette valeur est nulle,
// alors le carry passe a l'etat un, sinon a l'ettat zero.

void	inst_sti(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : STI\n", i);
}
