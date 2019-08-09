
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
	ft_printf("\npc = %d\n", plst->p.pc);
	ft_printf("\nreg_ind = %d\n", reg_index);

	return (plst->p.reg[reg_index]);
}

int		get_dir(t_corewar *cor, t_plst *plst)

int		get_param(t_corewar *cor, t_plst *plst, int type)
{
	if (type == REG_CODE)
		return (get_reg_value(cor, plst));
	if (type == DIR_CODE)
		return (get_dir(cor, plst));
//	if (type == IND_CODE)
//		return (get_ind(cor, plst));
	return (0);
}

void	inst_sti(t_corewar *cor, t_plst *plst)
{
	int	param1;
	int	param2;
//	int	param3;
	int	*type_param;

	ft_printf("process[%d] : STI\n", plst->p.id);

	type_param = check_opcode(cor, plst);
	ft_printf("type param 1 = %d\n", type_param[0]);
	ft_printf("type param 2 = %d\n", type_param[1]);
	ft_printf("type param 3 = %d\n", type_param[2]);

	param1 = get_param(cor, plst, type_param[0]);
	param2 = get_param(cor, plst, type_param[0]);
	//param1 = get_param(cor, plst, type_param[0]);
	ft_printf("param 1 = %d\n", param1);
}
