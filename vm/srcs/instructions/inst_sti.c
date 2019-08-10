
#include "../../includes/vm.h"

// sti | Indirect Store | 0x0B
// Usage : sti S(RG), S(RG/ID/D2), S(ID/D2) Durée : 25
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert indirect Registre > RAM. Charge la valeur contenu dans le
// registre passé en premier parametre a l'adresse resultante de
// l'addition des deux derniers paramametres. Si cette valeur est nulle,
// alors le carry passe a l'etat un, sinon a l'ettat zero.

int		get_reg_value(t_corewar *cor, t_plst *plst)
{
	int	reg_index;

	reg_index = get_reg_index(cor, plst);
	return (plst->p.reg[reg_index]);
}

int		get_small_dir(t_corewar *cor, t_plst *plst)
{
	int	direct;

	direct = cor->arena[plst->p.pc];
	direct = direct << 2;
	plst->p.pc =  pc_modulo(plst->p.pc + 1);
	direct = cor->arena[plst->p.pc];
	plst->p.pc =  pc_modulo(plst->p.pc + 1);
	return (direct);
}

int		get_ind(t_corewar *cor, t_plst *plst)
{
	int	addr;
	int	pc;

	pc = plst->p.pc;
	addr = get_small_dir(cor, plst);
	return (cor->arena[pc + addr]);
}

int		get_param(t_corewar *cor, t_plst *plst, int type)
{
	if (type == REG_CODE)
		return (get_reg_value(cor, plst));
	if (type == DIR_CODE)
		return (get_small_dir(cor, plst));
	if (type == IND_CODE)
		return (get_ind(cor, plst));
	return (0);
}

void	print_value(t_corewar *cor, int value, int addr)
{
	cor->arena[addr] = value >> 6;
	addr = pc_modulo(addr + 1);
	cor->arena[addr] = value >> 4;
	addr = pc_modulo(addr + 1);
	cor->arena[addr] = value >> 2;
	addr = pc_modulo(addr + 1);
	cor->arena[addr] = value;
}

void	inst_sti(t_corewar *cor, t_plst *plst)
{
	int	param1;
	int	param2;
	int	param3;
	int	*type_param;
	
	ft_printf("process[%d] : STI FINISHED\n", plst->p.id);
	
	//passe l'opcode
	plst->p.reg[1] = -1;
	plst->p.pc =  pc_modulo(plst->p.pc + 1);
	type_param = check_opcode(cor, plst);
	param1 = get_param(cor, plst, type_param[0]);
	pcode(cor, plst->p.pc + 3);
	param2 = get_param(cor, plst, type_param[1]);
	param3 = get_param(cor, plst, type_param[2]);
	ft_printf("param 1 = %d\n", param1);
	ft_printf("param 2 = %d\n", param2);
	ft_printf("param 3 = %d\n", param3);
	print_value(cor, param1, param2 + param3);
	print_arena_state(cor);
}
