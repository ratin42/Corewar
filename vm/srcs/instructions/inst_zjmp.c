#include "vm.h"

// zjmp | Jump if zero | 0x09
// Usage : zjmp S(D2) Durée : 20
// OCP : Non Adressage Restreint : Non Modifie le carry : Non
// Saute a l'adresse passé en parametre si le carry est a l'etat un.
// L'adresse devient alors celle de la prochaine instruction. Si le carry est
// a l'etat zero, rien ne se passe et le flot continue normalement jusqu'a
// l'instruction suivante. Rien ne precise si l'instruction consomme la
// totalité de ces cycles dans ce cas, a vous d'en decider

void	inst_zjmp(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;

	ft_print_debug(plst, "ZJMP", 0);
	ft_arg_init(&arg, 1, HALF, TRUE);
	arg.type[0] = DIR_CODE;
	arg.size[0] = 2;
	ft_get_args(cor, plst, &arg);
	if (plst->p.carry == 1)
		plst->p.pc = pc_modulo(plst->p.pc - 3 + ft_get_restricted_addr(arg.value[0]));
		//plst->p.pc = pc_modulo(plst->p.og_pc + arg.value[0]);
	else
		plst->p.pc %= MEM_SIZE;
	ft_print_debug(plst, "ZJMP", 1);
}
