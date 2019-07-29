/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:59:23 by saouas            #+#    #+#             */
/*   Updated: 2018/12/12 02:35:11 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t			size;
	char			*dest;

	dest = NULL;
	size = ft_strlen(s1);
	if (!(dest = (char *)malloc(sizeof(*dest) * (size + 1))))
		return (NULL);
	if (dest != NULL)
		ft_strcpy(dest, s1);
	return (dest);
}
