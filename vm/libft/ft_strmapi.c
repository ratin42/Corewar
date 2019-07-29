/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:40:10 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:19:38 by saouas           ###   ########.fr       */
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
	if (!(ret_str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		ret_str[i] = f(i, s[i]);
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
