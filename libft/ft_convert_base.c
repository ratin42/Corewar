/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:20:37 by saouas            #+#    #+#             */
/*   Updated: 2019/07/25 01:36:21 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long long int		give_base_nbr(char *base)
{
	return (ft_strlen(base));
}

long long int		base_to_decimal(char *nbr)
{
	long long int	len;
	long long int	nbr2;
	char			*str;

	nbr2 = ft_atoi_base(nbr, "0123456789");
	str = ft_litoa(nbr2);
	len = ft_strlen(str);
	free(str);
	return (nbr2);
}

char				*treat(char *base_to, long long int *tab,
long long int *size)
{
	long long int	i;
	long long int	tmp;
	char			*ret;

	if (!(ret = (char *)malloc(sizeof(char) * 1)))
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

char				*ft_convert_base_finale(char *nbr, char *base_to)
{
	long long int	calcul;
	long long int	size;
	long long int	tab[3];
	char			*ret;

	tab[0] = base_to_decimal(nbr);
	size = 1;
	calcul = base_to_decimal(nbr);
	if (calcul < 0)
	{
		calcul = calcul * -1;
		tab[2] = 1;
	}
	tab[1] = calcul;
	ret = treat(base_to, tab, &size);
	ft_reverse_str(ret, ft_strlen(ret));
	return (ret);
}
