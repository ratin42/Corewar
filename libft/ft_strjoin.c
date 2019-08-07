/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 21:52:15 by saouas            #+#    #+#             */
/*   Updated: 2019/08/06 18:16:19 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char		*str_ret;
	size_t		i;
	size_t		len;
	int			j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(str_ret = (char *)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str_ret[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		str_ret[i] = s2[j];
		i++;
		j++;
	}
	str_ret[i] = '\0';
	return (str_ret);
}
