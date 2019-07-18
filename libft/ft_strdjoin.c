/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 03:28:35 by ratin             #+#    #+#             */
/*   Updated: 2018/12/05 04:00:22 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdjoin(char *s1, char *s2)
{
	char	*str;

	if (s2)
	{
		if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcat(str, s1);
		ft_strcat(str, s2);
		ft_strdel(&s1);
		return (str);
	}
	return (NULL);
}
