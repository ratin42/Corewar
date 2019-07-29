/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:01:22 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:12:43 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		cc;
	size_t	i;

	i = 0;
	cc = (unsigned char)c;
	while (i != len)
	{
		((char *)(b))[i] = cc;
		i++;
	}
	return (b);
}
