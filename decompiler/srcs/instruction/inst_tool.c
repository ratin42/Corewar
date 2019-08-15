#include "decompile.h"

char		*get_reg_index(t_corewar *cor)
{
	int 	reg;
	char	*result;

	reg = cor->code[cor->pc];
	cor->pc++;
	result = ft_strjoin_free("r", ft_itoa(reg), 2);
	return (result);
}

int		*check_opcode(t_corewar *cor)
{
	int	param1;
	int	param2;
	int	param3;
	int	*type_param;

	if (!(type_param = ft_memalloc(sizeof(int) * 3)))
		decomp_quit("Malloc error");
	param1 = ((cor->code[cor->pc] >> 6) & 0x3);
	type_param[0] = param1;
	param2 = ((cor->code[cor->pc] >> 4) & 0x3);
	type_param[1] = param2;
	param3 = ((cor->code[cor->pc] >> 2) & 0x3);
	type_param[2] = param3;
	cor->pc++;
	return (type_param);
}

int		check_registre_index(int reg_1, int reg_2, int reg_3)
{
	if (reg_1 < 1 || reg_1 > 16)
		return (0);
	if (reg_2 < 1 || reg_2 > 16)
		return (0);
	if (reg_3 < 1 || reg_3 > 16)
		return (0);
	return (1);
}

int		ft_get_restricted_addr(int value)
{
	value %= MEM_SIZE;
	if (value >= MEM_SIZE - IDX_MOD)
		return (value);
	else
		return (value % IDX_MOD);
}

char		*get_small_dir(t_corewar *cor)
{
	unsigned int	direct;
	char	*result;

	direct = cor->code[cor->pc];
	direct = direct << 8;
	cor->pc++;
	direct += cor->code[cor->pc];
	cor->pc++;
	result = ft_strjoin_free("%", ft_itoa((char)direct), 2);
	return (result);
}

char		*get_big_dir(t_corewar *cor)
{
	unsigned int	direct;
	char	*result;

	direct = cor->code[cor->pc];
	direct = direct << 8;
	cor->pc++;
	direct += cor->code[cor->pc];
	direct = direct << 8;
	cor->pc++;
	direct += cor->code[cor->pc];
	direct = direct << 8;
	cor->pc++;
	direct += cor->code[cor->pc];
	cor->pc++;
	result = ft_strjoin_free("%", ft_itoa((char)direct), 2);
	return (result);
}

char		*get_ind(t_corewar *cor)
{
	int		direct;
	char	*result;

	direct = cor->code[cor->pc];
	direct = direct << 8;
	cor->pc++;
	direct += cor->code[cor->pc];
	cor->pc++;
	result = ft_itoa((char)direct);
	return (result);
}
