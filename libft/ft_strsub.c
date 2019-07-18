/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 22:13:53 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:21:57 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str_ret;
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	j = start;
	i = 0;
	if (!(str_ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str_ret[i] = s[j];
		i++;
		j++;
	}
	str_ret[i] = '\0';
	return (str_ret);
}
