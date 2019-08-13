/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 16:47:45 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:21:22 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strrchr(const char *str, int c)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str);
	if (c == '\0')
		return ((char *)str + ft_strlen(str));
	while (i >= 0)
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}
