/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlombard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:27:07 by hlombard          #+#    #+#             */
/*   Updated: 2019/08/15 22:27:50 by hlombard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, long long int newsize)
{
	char			*newptr;
	long long int	current_size;

	if (ptr == 0)
		return (ft_memalloc(newsize));
	current_size = ft_strlen(ptr);
	if (newsize <= current_size)
		return (ptr);
	if ((newptr = ft_memalloc(newsize)) == NULL)
		return (0);
	ft_strcpy(newptr, ptr);
	free(ptr);
	return (newptr);
}
