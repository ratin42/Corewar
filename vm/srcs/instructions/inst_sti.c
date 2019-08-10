
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

int		get_param(t_corewar *cor, t_plst *plst, int type)
{
	if (type == REG_CODE)
		return (get_reg_value(cor, plst));
	if (type == DIR_CODE)
		return (get_small_dir(cor, plst));
//	if (type == IND_CODE)
//		return (get_ind(cor, plst));
	return (0);
}

void	inst_sti(t_corewar *cor, t_plst *plst)
{
	int	param1;
	int	param2;
	int	param3;
	int	*type_param;
	
	plst->p.reg[1] = 42; //debug
	ft_printf("process[%d] : STI\n", plst->p.id);
	
	//passe l'opcode
	plst->p.pc =  pc_modulo(plst->p.pc + 1);
	type_param = check_opcode(cor, plst);
/* 	ft_printf("type param 1 = %d\n", type_param[0]);
	ft_printf("type param 2 = %d\n", type_param[1]);
	ft_printf("type param 3 = %d\n", type_param[2]); */

	param1 = get_param(cor, plst, type_param[0]);
	param2 = get_param(cor, plst, type_param[1]);
	param3 = get_param(cor, plst, type_param[2]);
	ft_printf("param 1 = %d\n", param1);
	ft_printf("param 2 = %d\n", param2);
	ft_printf("param 3 = %d\n", param3);
	pcode(cor, plst->p.pc);
	//print_value(cor, plst, param1, param1 + param2);
}
