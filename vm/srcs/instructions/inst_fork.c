#include "vm.h"

// fork | Fork | 0x0C
// Usage : fork S(D2) Durée : 800
// OCP : Non Adressage Restreint : Oui Modifie le carry : Non
// Genere un nouveau processus a l'adresse passée en parametre par
// copie du processus appelant. Le nouveau processus garde donc
// l'etat de tout les registres et du carry, seul le PC differe ( sauf dans le
// cas d'un fork %0 ).

void	inst_fork(t_corewar *cor, t_plst *plst)
{
	t_arg	arg;
	t_plst	*elem;

	ft_arg_init(&arg, 1, HALF, TRUE);
	arg.type[0] = DIR_CODE;
	arg.size[0] = 2;
	ft_get_args(cor, plst, &arg);
	if (!(elem = malloc(sizeof(t_plst))))
		corewar_quit("Fail malloc");//voir si on met autre chose ou pas
	plst->p.opcode = 0;
	ft_memcpy(elem, plst, sizeof(t_plst));
	elem->p.pc = pc_modulo(plst->p.og_pc + ft_get_restricted_addr(arg.value[0]));
	elem->next = cor->plst;
	cor->plst = elem;
	cor->nb_process++;
	if (DEBUG)
	{
		printf("##########  DEBUG FORK  ##########\n");
		ft_print_plst(cor->plst);
	}
}
