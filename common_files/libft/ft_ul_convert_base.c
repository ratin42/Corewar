/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ul_convert_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 15:29:31 by saouas            #+#    #+#             */
/*   Updated: 2019/08/15 22:12:43 by hlombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	give_base_nbr(char *base)
{
	return (ft_strlen(base));
}

static unsigned long long int	u_base_to_decimal(char *nbr)
{
	unsigned long long int		len;
	unsigned long long int		nbr2;
	char						*str;

	nbr2 = atoul_base(nbr, "0123456789");
	str = ft_lutoa(nbr2);
	len = ft_strlen(str);
	free(str);
	return (nbr2);
}

static char						*treat(char *base_to,
		unsigned long long int *tab, unsigned long long int *size)
{
	unsigned long long int		i;
	unsigned long long int		tmp;
	char						*ret;

	if (!(ret = (char *)ft_memalloc(sizeof(char) * 1)))
		return (NULL);
	tmp = 0;
	i = 0;
	while (tab[1] != 0)
	{
		ret = ft_realloc(ret, (*size)++);
		tmp = tab[1] / give_base_nbr(base_to);
		ret[i] = base_to[tab[1] % give_base_nbr(base_to)];
		tab[1] = tmp;
		i++;
	}
	ret[i] = '\0';
	if (tab[2] == 1)
	{
		ret = ft_realloc(ret, ++(*size));
		ret[i++] = '-';
	}
	ret[i] = '\0';
	return (ret);
}

char							*ft_ul_convert_base(char *nbr,
		char *base_to)
{
	unsigned long long int		calcul;
	unsigned long long int		size;
	unsigned long long int		tab[3];
	char						*ret;

	tab[0] = u_base_to_decimal(nbr);
	size = 1;
	calcul = u_base_to_decimal(nbr);
	tab[1] = calcul;
	ret = treat(base_to, tab, &size);
	ft_reverse_str(ret, ft_strlen(ret));
	return (ret);
}
