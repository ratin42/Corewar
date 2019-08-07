#include "../../includes/vm.h"

// fork | Fork | 0x0C
// Usage : fork S(D2) Durée : 800
// OCP : Non Adressage Restreint : Oui Modifie le carry : Non
// Genere un nouveau processus a l'adresse passée en parametre par
// copie du processus appelant. Le nouveau processus garde donc
// l'etat de tout les registres et du carry, seul le PC differe ( sauf dans le
// cas d'un fork %0 ).

void	inst_fork(t_corewar *cor, int i)
{
	(void)cor;
	ft_printf("process[%d] : FORK\n", i);
}
