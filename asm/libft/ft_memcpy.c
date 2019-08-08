/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:38:08 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:10:58 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dstt;
	const char	*srcc;
	size_t		i;

	i = 0;
	srcc = (char *)src;
	dstt = (char *)dst;
	while (i < n)
	{
		dstt[i] = srcc[i];
		i++;
	}
	return (dst);
}
