#include "../../includes/vm.h"

// zjmp | Jump if zero | 0x09
// Usage : zjmp S(D2) Durée : 20
// OCP : Non Adressage Restreint : Non Modifie le carry : Non
// Saute a l'adresse passé en parametre si le carry est a l'etat un.
// L'adresse devient alors celle de la prochaine instruction. Si le carry est
// a l'etat zero, rien ne se passe et le flot continue normalement jusqu'a
// l'instruction suivante. Rien ne precise si l'instruction consomme la
// totalité de ces cycles dans ce cas, a vous d'en decider

// static int		get_param(t_corewar *cor, t_plst *plst, int type)
// {
// 	if (type == REG_CODE)
// 		return (get_reg_value(cor, plst));
// 	if (type == DIR_CODE)
// 		return (get_small_dir(cor, plst));
// 	if (type == IND_CODE)
// 		return (get_ind(cor, plst));
// 	return (0);
// }

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
	// int param1;
	// //int *type_param;

	// //type_param = check_opcode(cor, plst);
	// param1 = get_param(cor, plst, DIR_CODE);
	// // if (type_param[0] != DIR_CODE)
	// // 	return ;
	plst->p.carry = 1;
	if (plst->p.carry == 1)
	{
		ft_printf("pc before = %d\n", plst->p.pc);
		// plst->p.pc = ((plst->p.pc + 3) + (param1 % IDX_MOD)) % MEM_SIZE;
		plst->p.pc = pc_modulo(plst->p.pc - 3 + ft_get_restricted_addr(arg.value[0]));
		//plst->p.pc = ((plst->p.pc - 3) + (arg.value[0] % IDX_MOD)) % MEM_SIZE;
		//PC = ( PC + ( param % IDXMOD ) ) % MEMSIZE
	}
	else
		plst->p.pc = (plst->p.pc + 3) % MEM_SIZE;
	
	ft_printf("param1 = %d\n", arg.value[0]);
	ft_printf("pc after = %d\n", plst->p.pc);
}