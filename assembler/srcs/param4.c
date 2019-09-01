/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:52:25 by syzhang           #+#    #+#             */
/*   Updated: 2019/09/01 20:06:35 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		check_end_coma(t_asm *asmbly, char *str, int line)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			return ;
		i++;
	}
	if (str[ft_strlen(str) - 1] == ',')
	{
		ft_putstr_fd("Syntax error ENDLINE line ", 2);
		ft_putnbr_fd(line, 2);
		ft_putchar_fd('\n', 2);
		quit_prog(asmbly);
	}
}

void		get_params(t_asm *asmbly, char *str, int line)
{
	t_instru	*instru;
	int			i;

	i = 0;
	if (!(instru = find_instru(asmbly, line)))
		instru = get_last_instru(asmbly);
	instru->nbr_of_params = get_nbr_of_params(instru->opcode);
	while ((str[i] != 32 && (str[i] < 9 || str[i] > 13)) && str[i])
		i++;
	check_end_coma(asmbly, str, line);
	fill_params(asmbly, &instru, &str[i], line);
	get_params_type(asmbly, &str[i], line);
}

void		error_comma(t_asm *asmbly, char *str, int line, int i)
{
	if (str[i] == ',' && str[i + 1] == ',')
	{
		ft_putstr_fd("Error double comma at line ", 2);
		ft_putnbr_fd(line, 2);
		ft_putchar_fd('\n', 2);
		quit_prog(asmbly);
	}
}
