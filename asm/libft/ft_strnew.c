/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:19:44 by saouas            #+#    #+#             */
/*   Updated: 2019/08/06 18:16:28 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strnew(size_t size)
{
	size_t		i;
	char		*ret_str;

	i = 0;
	if (!(ret_str = (char *)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size + 1)
	{
		ret_str[i] = '\0';
		i++;
	}
	return (ret_str);
}
