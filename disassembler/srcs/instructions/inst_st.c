#include "vm.h"

// st | Direct Store | 0x03
// Usage : st S(RG), D(RG/ID) Durée : 5
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Oui
// Transfert direct Registre > RAM / Registre. Charge le contenu du
// registre passé en premier parametre dans le second parametre. Si la
// valeur du premier parametre est egale a zero, alors le carry passe a
// l'etat un, sinon a l'etat zero.

static int	get_param(t_corewar *cor, t_plst *plst, int type)
{
	if (type == REG_CODE)
		return (get_reg_value(cor, plst));
	if (type == IND_CODE)
		return (get_small_dir(cor, plst));
	return (0);
}

void		fill_value(t_corewar *cor, t_plst *plst, int param[2] , int type)
{
	if (type == REG_CODE)
		plst->p.reg[param[1]] = param[0];
	else
		print_value(cor, param[0], plst->p.og_pc
			+ ft_get_restricted_addr(param[1]), plst);	
}

void		inst_st(t_corewar *cor, t_plst *plst)
{
	int		*instru_type;
	int		param[2];
	
	ft_print_debug(plst, "ST", 0);
	instru_type = check_opcode(cor, plst);
	param[0] = get_param(cor, plst, instru_type[0]);
	if (instru_type[1] == IND_CODE)
		param[1] = get_param(cor, plst, instru_type[1]);
	else
	{
		param[1] = get_reg_index(cor, plst);
		if (check_registre_index(param[1], 1, 1) == 0)
			return ;
	}
	if (instru_type[0] != REG_CODE || (instru_type[1] != REG_CODE
		&& instru_type[1] != IND_CODE))
		return ;
	fill_value(cor, plst, param, instru_type[1]);
	free(instru_type);
	ft_print_debug(plst, "ST", 1);
}
