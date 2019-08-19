/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoul_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:14:58 by hlombard          #+#    #+#             */
/*   Updated: 2019/08/15 22:15:41 by hlombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long int		atoul_base(char *str, char *base)
{
	unsigned long long int	s;
	unsigned long int		i;
	unsigned long long int	res;
	unsigned long long int	negative;
	unsigned long long int	base_length;

	base_length = 0;
	while (base[base_length])
		++base_length;
	s = 0;
	while (str[s] != '\0' && (str[s] == ' ' || str[s] == '\t'
				|| str[s] == '\r' || str[s] == '\n' || str[s] == '\v' || str[s] == '\f'))
		s++;
	i = s - 1;
	res = 0;
	negative = 1;
	while (str[++i] && (((str[i] == '-' || str[i] == '+') && i == s) ||
				(str[i] != '-' && str[i] != '+')))
		if (str[i] == '-')
			negative = -1;
		else if (str[i] != '+')
			res = (res * base_length) + (get_nb(str[i], base));
	return (res * negative);
}
