/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:59:23 by saouas            #+#    #+#             */
/*   Updated: 2019/08/06 18:16:02 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		i;
	int		y;

	i = ft_strlen(s1);
	y = 0;
	if ((cpy = (char *)ft_memalloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
		return (0);
	while (i > 0)
	{
		cpy[y] = s1[y];
		y++;
		i--;
	}
	cpy[y] = '\0';
	return (cpy);
}