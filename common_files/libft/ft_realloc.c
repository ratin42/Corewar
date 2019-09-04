/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 22:27:07 by hlombard          #+#    #+#             */
/*   Updated: 2019/09/04 14:01:36 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *ptr, long long int newsize)
{
	char			*newptr;
	long long int	current_size;

	newptr = NULL;
	current_size = 0;
	if (ptr == NULL)
		return (ft_memalloc(newsize));
	current_size = ft_strlen(ptr);
	if (newsize <= current_size)
		return (ptr);
	//return (realloc(ptr, newsize));
	if ((newptr = ft_memalloc(newsize)) == NULL)
		return (0);
	ft_strcpy(newptr, ptr);
	free(ptr);
	return (newptr);
}
