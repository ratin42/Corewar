
#include "vm.h"

// sti | Indirect Store | 0x0B
// Usage : sti S(RG), S(RG/ID/D2), S(RG/D2) Durée : 25
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

void	print_value(t_corewar *cor, int value, int addr, t_plst *plst)
{
	char	a;
	char	b;
	char	c;
	char	d;

	//printf("size of int = %lu\n", sizeof(int));
	a = ((value >> 24) & 0xFF);
	b = ((value >> 16) & 0xFF);
	c = ((value >> 8) & 0xFF);
	d = value & 0xFF;
	addr = pc_modulo(addr);
	//printf("stocking ->|%02x|\n", a);
	cor->arena[addr] = a;
	cor->render.bold[addr] = 50;
	cor->render.mem_owner[addr] = re_adjust_id(plst->p.id, &plst->p) + 1;
	
	addr = pc_modulo(addr + 1);
	//printf("stocking ->|%02x|\n", b);
	cor->arena[addr] = b;
	cor->render.bold[addr] = 50;
	cor->render.mem_owner[addr] = re_adjust_id(plst->p.id, &plst->p) + 1;

	addr = pc_modulo(addr + 1);
	//printf("stocking ->|%02x|\n", c);
	cor->arena[addr] = c;
	cor->render.bold[addr] = 50;
	cor->render.mem_owner[addr] = re_adjust_id(plst->p.id, &plst->p) + 1;

	addr = pc_modulo(addr + 1);
	//printf("stocking ->|%02x|\n", d);
	cor->arena[addr] = d;
	cor->render.bold[addr] = 50;
	cor->render.mem_owner[addr] = re_adjust_id(plst->p.id, &plst->p) + 1;
}

void	inst_sti(t_corewar *cor, t_plst *plst)
{
	ft_print_debug(plst, "STI", 0);
	int	param1;
	int	param2;
	int	param3;
	int	*type_param;
	
	//printf("\nsti cycle = %d======================================\n", cor->total_cycle);
	type_param = check_opcode(cor, plst);
	param1 = get_param(cor, plst, type_param[0]);
	param2 = get_param(cor, plst, type_param[1]);
	param3 = get_param(cor, plst, type_param[2]);
	if (type_param[0] != REG_CODE || type_param[1] == 0 || (type_param[2]
		!= DIR_CODE && type_param[2] != REG_CODE))
	{
		free(type_param);
		return ;
	}
	if (DEBUG)
	{
		ft_printf("param 1 = %d\n", param1);
		ft_printf("param 2 = %d\n", param2);
		ft_printf("param 3 = %d\n", param3);
	}
	print_value(cor, param1, plst->p.og_pc + ft_get_restricted_addr(param2 + param3), plst);
	free(type_param);
	ft_print_debug(plst, "STI", 1);
}
