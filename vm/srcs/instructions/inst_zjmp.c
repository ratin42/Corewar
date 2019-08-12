#include "../../includes/vm.h"

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
	//(void)cor;
	//ft_printf("process[%d] : ZJMP\n", i); 
	ft_printf("ZJMP\n");

	t_arg	arg;

	ft_arg_init(&arg, 1, HALF, TRUE);
	arg.type[0] = DIR_CODE;
	arg.size[0] = 2;
	ft_get_args(cor, plst, &arg);
	//plst->p.carry = 1;
	if (plst->p.carry == 1)
	{
		ft_printf("pc before = %d\n", plst->p.pc);
		// plst->p.pc = ((plst->p.pc + 3) + (param1 % IDX_MOD)) % MEM_SIZE;
		plst->p.pc = pc_modulo(plst->p.pc - 3 + ft_get_restricted_addr(arg.value[0]));
	}
	else
		plst->p.pc %= MEM_SIZE;
	
	ft_printf("param1 = %d\n", arg.value[0]);
	ft_printf("pc after = %d\n", plst->p.pc);
}