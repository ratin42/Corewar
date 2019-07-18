/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreedup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 20:51:51 by ratin             #+#    #+#             */
/*   Updated: 2019/02/24 20:57:08 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strfreedup(char *s1)
{
	size_t			size;
	char			*dest;

	dest = NULL;
	size = ft_strlen(s1);
	if (!(dest = (char *)malloc(sizeof(*dest) * (size + 1))))
		return (NULL);
	if (dest != NULL)
		ft_strcpy(dest, s1);
	free(s1);
	return (dest);
}
