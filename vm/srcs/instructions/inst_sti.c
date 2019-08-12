
#include "../../includes/vm.h"

// sti | Indirect Store | 0x0B
// Usage : sti S(RG), S(RG/ID/D2), S(ID/D2) Durée : 25
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert indirect Registre > RAM. Charge la valeur contenu dans le
// registre passé en premier parametre a l'adresse resultante de
// l'addition des deux derniers paramametres. Si cette valeur est nulle,
// alors le carry passe a l'etat un, sinon a l'ettat zero.


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
	
	//plst->p.pc =  pc_modulo(plst->p.pc + 1);
	type_param = check_opcode(cor, plst);
	param1 = get_param(cor, plst, type_param[0]);
	param2 = get_param(cor, plst, type_param[1]);
	param3 = get_param(cor, plst, type_param[2]);
	/*
	if (type_param[0] != REG_CODE || type_param[1] == 0 || (type_param[2]
		!= DIR_CODE && type_param[2] != REG_CODE))
		return ;
		*/
	if (DEBUG)
	{
		ft_printf("param 1 = %d\n", param1);
		ft_printf("param 2 = %d\n", param2);
		ft_printf("param 3 = %d\n", param3);
	}
	print_value(cor, param1, param2 + param3);
	free(type_param);
}
