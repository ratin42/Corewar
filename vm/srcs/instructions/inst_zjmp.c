#include "../../includes/vm.h"

// zjmp | Jump if zero | 0x09
// Usage : zjmp S(D2) Durée : 20
// OCP : Non Adressage Restreint : Non Modifie le carry : Non
// Saute a l'adresse passé en parametre si le carry est a l'etat un.
// L'adresse devient alors celle de la prochaine instruction. Si le carry est
// a l'etat zero, rien ne se passe et le flot continue normalement jusqu'a
// l'instruction suivante. Rien ne precise si l'instruction consomme la
// totalité de ces cycles dans ce cas, a vous d'en decider

void	inst_zjmp(t_corewar *cor, int i)
{
	// (void)cor;
	ft_printf("process[%d] : ZJMP\n", i);
	int pc;

	if (cor->process[i].carry == 1)
	{
		pc = (cor->process[i].pc + 2) % MEM_SIZE;
		//PC = ( PC + ( param % IDXMOD ) ) % MEMSIZE
		cor->process[i].pc = pc;
	}
}
