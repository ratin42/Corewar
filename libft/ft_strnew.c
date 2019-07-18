/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:19:44 by saouas            #+#    #+#             */
/*   Updated: 2019/04/26 20:34:11 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strnew(size_t size)
{
	size_t		i;
	char		*ret_str;

	i = 0;
	if (!(ret_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size + 1)
	{
		ret_str[i] = '\0';
		i++;
	}
	return (ret_str);
}
