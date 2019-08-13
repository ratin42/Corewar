/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:06:16 by saouas            #+#    #+#             */
/*   Updated: 2019/08/06 18:15:54 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
