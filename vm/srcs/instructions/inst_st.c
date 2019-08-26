#include "vm.h"

// st | Direct Store | 0x03
// Usage : st S(RG), D(RG/ID) Durée : 5
// OCP : Oui Adressage Restreint : Oui Modifie le carry : Non
// Transfert direct Registre > RAM / Registre. Charge le contenu du
// registre passé en premier parametre dans le second parametre.

static int	get_param(t_corewar *cor, t_plst *plst, int type, int *flag_error)
{
	if (type == REG_CODE)
		return (get_reg_value(cor, plst, &flag_error));
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
	int		flag_error;
	
	flag_error = 0;
	ft_print_debug(plst, "ST", 0);
	instru_type = check_opcode(cor, plst);
	param[0] = get_param(cor, plst, instru_type[0], &flag_error);
	if (instru_type[1] == IND_CODE)
		param[1] = get_param(cor, plst, instru_type[1], &flag_error);
	else
	{
		param[1] = get_reg_index(cor, plst);
		if (check_registre_index(param[1], 1, 1) == 0)
		{	
			free(instru_type);
			return ;
		}
	}
	if (flag_error == -1)
	{
		free(instru_type);
		return ;
	}
	if (instru_type[0] != REG_CODE || (instru_type[1] != REG_CODE
		&& instru_type[1] != IND_CODE))
	{

		free(instru_type);
		return ;
	}
	fill_value(cor, plst, param, instru_type[1]);
	free(instru_type);
	ft_print_debug(plst, "ST", 1);
}
