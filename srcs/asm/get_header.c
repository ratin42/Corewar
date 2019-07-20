/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:42:13 by ratin             #+#    #+#             */
/*   Updated: 2019/07/20 22:06:49 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_name(t_asm *asmbly, char *str)
{
	size_t	i;
	char	*name;

	name = NAME_CMD_STRING;
	i = 0;
	while (str[i] && i < ft_strlen(NAME_CMD_STRING))
	{
		if (str[i] != name[i])
		{
			ft_putstr("Lexical error for name at [1:");
			ft_putnbr(i);
			ft_putstr("]\n");
			exit(ERROR);
		}
		i++;
	}
	if (!(asmbly->name = ft_strdup(&str[i])))
	{
		free(str);
		exit(ERROR);
	}
}

void	get_comment(t_asm *asmbly, char *str)
{
	size_t	i;
	char	*comment;

	comment = COMMENT_CMD_STRING;
	i = 0;
	while (str[i] && i < ft_strlen(COMMENT_CMD_STRING))
	{
		if (str[i] != comment[i])
		{
			ft_putstr("Lexical error for comment at [2:");
			ft_putnbr(i);
			ft_putstr("]\n");
			exit(ERROR);
		}
		i++;
	}
	if (!(asmbly->comment = ft_strdup(&str[i])))
	{
		free(str);
		exit(ERROR);
	}
}