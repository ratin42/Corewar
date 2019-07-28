/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 20:20:02 by ratin             #+#    #+#             */
/*   Updated: 2019/07/28 18:51:29 by ratin            ###   ########.fr       */
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

int        nbr_len(int nb)
{
    int len;

    len = 0;
    if (nb == 0)
        return (1);
    if (nb < 0)
    {
        len++;
        nb *= -1;
    }
    while (nb)
    {
        len++;
        nb /= 10;
    }
    return (len);
}

char				*fill_bincode(char *bin_code)
{
	while (ft_strlen(bin_code) < 8)
	{
		if (!(bin_code = ft_strjoin_free(bin_code, "00", 1)))
			exit(ERROR);
	}
	return (bin_code);
}

char				*get_ocp(t_instru *instru)
{
	t_param			*param;
	int				decimal_code;
	char			*bin_code;
	char			*result;
	char			*d_code;

	param = instru->param;
	if (!(bin_code = ft_strnew(0)))
		exit(ERROR);
	while (param)
	{
		if (param->type == 1)
		{
			if (!(bin_code = ft_strjoin_free(bin_code, "01", 1)))
				exit(ERROR);
		}
		if (param->type == 2)
		{
			if (!(bin_code = ft_strjoin_free(bin_code, "10", 1)))
				exit(ERROR);
		}
		if (param->type == 4)
		{
			if (!(bin_code = ft_strjoin_free(bin_code, "11", 1)))
				exit(ERROR);
		}
		param = param->next;
	}
	if (ft_strlen(bin_code) < 8)
		bin_code = fill_bincode(bin_code);
	decimal_code = binary_to_decimal(ft_atoi(bin_code));
	d_code = ft_itoa(decimal_code);
	result = ft_convert_base_finale(d_code, "0123456789abcdef");
	free(d_code);
	free(bin_code);
	return (result);
}
