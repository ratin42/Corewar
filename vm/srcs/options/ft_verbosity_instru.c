#include "vm.h"

static inline void	ft_print_verbo_normal(t_plst *plst, t_arg arg)
{
	int		i;

	i = 0;
	while (i < arg.nb_arg)
	{
		if (arg.type[i] == REG_CODE)
			ft_printf(" r%d", arg.value[i]);
		else
			ft_printf(" %d", arg.value[i]);
		i++;
	}
	if (plst->p.opcode != 12 && plst->p.opcode != 15 && plst->p.opcode != 9)
		ft_putstr("\n");
}

static inline void	ft_print_verbo_indirect(t_plst *plst, t_arg arg)
{
	int		sti;
	int		lldi;
	int		value;

	sti = plst->p.opcode == 11 ? 1 : 0;
	lldi = plst->p.opcode == 14 ? 1 : 0;
	value = arg.value[0 + sti] + arg.value[1 + sti];
	ft_printf("       | -> %s %d + %d = %d (with %s %d)\n",
		sti ? "store to" : "load from",
		arg.value[0 + sti], arg.value[1 + sti], value,
		lldi ? "pc" : "pc and mod", lldi ? value + plst->p.og_pc
		: ft_get_restricted_addr(value + plst->p.og_pc));
}

static inline void	ft_print_verbo_special(t_corewar *cor, t_plst *plst, t_arg arg)
{
	int		index;

	if (plst->p.opcode == 12 || plst->p.opcode == 15)
		ft_printf(" (%d)\n", plst->p.opcode == 12
			? ft_get_restricted_addr(arg.value[0] + plst->p.og_pc)
			: arg.value[0] + plst->p.og_pc);
	else if (plst->p.opcode == 9)
		ft_printf(" %s\n", plst->p.carry ? "OK" : "FAILED");
	else
	{
		index = ft_get_player_index(cor, arg.value[0]);
		if (index != -1)
			ft_printf("Player %d (%s) is said to be alive.\n",
				arg.value[0] * -1, cor->player[index].name);
	}
}

void				ft_verbosity_instru(t_corewar *cor, t_plst *plst, t_arg arg)
{
	int		length;
	int		i;

	if (!cor->verbosity || cor->visu)
		return ;
	if ((cor->v_lvl & VERBO3) && plst->p.opcode != 16)
	{
		ft_printf("P%5d | %s", plst->n_plst, g_op_tab[plst->p.opcode - 1].name);
		ft_print_verbo_normal(plst, arg);
		if (arg.verbo & INDIRECT)
			ft_print_verbo_indirect(plst, arg);
		else if (arg.verbo & SPECIAL)
			ft_print_verbo_special(cor, plst, arg);
	}
	if ((cor->v_lvl & VERBO5) && (plst->p.opcode != 9 || plst->p.carry == 0))
	{
		length = plst->p.pc - plst->p.og_pc;
		ft_printf("ADV %d (0x%04x -> %#06x) ", length, plst->p.og_pc, plst->p.pc);
		i = 0;
		while (i < length)
		{
			ft_printf("%02x ", cor->arena[pc_modulo(plst->p.og_pc + i)]);
			i++;
		}
		ft_putstr("\n");
	}
}
