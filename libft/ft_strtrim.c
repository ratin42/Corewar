/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:30:08 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:22:10 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		is_white_spaces(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *str)
{
	int		i;
	int		len;
	char	*str_ret;
	int		j;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (str[i] && is_white_spaces(str[i]))
		i++;
	if (str[i] == '\0')
		return (ft_strdup(str + i));
	len--;
	while (str[len] && is_white_spaces(str[len]))
		len--;
	if (!(str_ret = (char *)malloc(sizeof(char) * ((len - i) + 2))))
		return (NULL);
	while (i <= len)
		str_ret[j++] = str[i++];
	str_ret[j] = '\0';
	return (str_ret);
}
