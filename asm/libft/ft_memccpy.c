/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:01:25 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:11:52 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dstt;
	unsigned char	*srcc;
	size_t			i;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	srcc = (unsigned char *)src;
	dstt = (unsigned char *)dst;
	while (i < n)
	{
		dstt[i] = srcc[i];
		if (srcc[i] == cc)
		{
			i++;
			return (dstt + i);
		}
		i++;
	}
	return (NULL);
}
