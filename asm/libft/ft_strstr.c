/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:12:16 by saouas            #+#    #+#             */
/*   Updated: 2019/04/15 13:02:15 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int y;

	i = 0;
	y = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		y = 0;
		while (needle[y] == haystack[i + y])
		{
			if (needle[y + 1] == '\0')
				return (&((char *)haystack)[i]);
			y++;
		}
		i++;
	}
	return (NULL);
}
