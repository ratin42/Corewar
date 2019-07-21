/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:27:45 by ratin             #+#    #+#             */
/*   Updated: 2019/07/21 23:57:04 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_erro_param(char *str, int line)
{
	ft_putstr("Lexical error for param [");
	ft_putnbr(line);
	ft_putchar(':');
	ft_putnbr(0);
	ft_putstr("] ->");
	ft_putstr(str);
	ft_putchar('\n');
	exit(ERROR);
}

void			fill_params(t_asm *asmbly, char *str, int line)
{
	t_instru	*instru;
	int			param_nbr;
	int			i;
	int			y;
	char		*param;

	i = 0;
	param_nbr = 0;
	instru = find_instru(asmbly, line);
	while (param_nbr < instru->nbr_of_params)
	{
		if (str[i] != ' ')
			print_erro_param(str, line);
		y = 0;
		i++;
		while (str[i + y] != ',' && str[i + y])
			y++;
		param = ft_strsub(str, i, y);
		add_param(instru, line, param);
		free(param);
		i += y + 1;
		param_nbr++;
	}
}
