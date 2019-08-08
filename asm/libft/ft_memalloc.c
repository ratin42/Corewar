/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:29:52 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:10:44 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		*ft_memalloc(size_t size)
{
	void		*ret_str;
	size_t		i;

	ret_str = NULL;
	i = 0;
	if (!(ret_str = malloc(sizeof(ret_str) * (size))))
		return (NULL);
	return (ft_memset(ret_str, 0, size));
}
