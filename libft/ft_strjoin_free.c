/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:06:30 by ratin             #+#    #+#             */
/*   Updated: 2019/02/24 21:09:29 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin_free(char const *s1, char const *s2, int string)
{
	char	*str;

	if (!s1)
		return (ft_strfreedup((char *)s2));
	if (!s2)
		return (ft_strfreedup((char *)s1));
	if ((str = (char *)ft_memalloc(sizeof(char) *
	(ft_strlen(s1) + ft_strlen(s2) + 1))) == NULL)
	{
		free((void *)s1);
		free((void *)s2);
		return (0);
	}
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (string == 1 || string == 3)
		free((void *)s1);
	if (string == 2 || string == 3)
		free((void *)s2);
	return (str);
}
