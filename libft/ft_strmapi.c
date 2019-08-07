/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:40:10 by saouas            #+#    #+#             */
/*   Updated: 2019/08/06 18:16:24 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret_str;
	unsigned int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!(ret_str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		ret_str[i] = f(i, s[i]);
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
