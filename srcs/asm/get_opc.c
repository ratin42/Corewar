/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:20:02 by ratin             #+#    #+#             */
/*   Updated: 2019/07/25 20:33:01 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

long long int		ft_pow(int x, unsigned int y)
{
	long long int	tmp;

	tmp = 1;
	if (y == 0)
		return (tmp);
	else
		while (y != 0)
		{
			tmp = x * tmp;
			y--;
		}
	return (tmp);
}

int					binary_to_decimal(long long n)
{
    int				decimalNumber;
	int				i;
	int				remain;

	decimalNumber = 0;
	i = 0;
    while (n != 0)
    {
        remain = n % 10;
        n = n / 10;
        decimalNumber = decimalNumber + (remain * ft_pow(2, i));
        ++i;
    }
    return (decimalNumber);
}

char				*get_opc(t_instru *instru)
{
	t_param			*param;
	int				decimal_code;
	long long		bin_code;
	char			*result;
	char			*d_code;

	param = instru->param;
	bin_code = 0;
	while (param)
	{
		if (param->type == 1)
			bin_code = bin_code * 100 + 01;
		if (param->type == 2)
			bin_code = bin_code * 100 + 10;
		if (param->type == 4)
			bin_code = bin_code * 100 + 11;
		param = param->next;
	}
	bin_code = bin_code * 100;
	decimal_code = binary_to_decimal(bin_code);
	d_code = ft_itoa(decimal_code);
	result = ft_convert_base_finale(d_code, "0123456789abcdef");
	free(d_code);
	return (result);
}
