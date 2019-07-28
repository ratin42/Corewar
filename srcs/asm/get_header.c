/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:42:13 by ratin             #+#    #+#             */
/*   Updated: 2019/07/28 17:14:59 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_error(char *str)
{
	ft_putstr("Lexical error for");
	ft_putstr(str);
	ft_putstr("\n");
	
	(void)str;
	exit(ERROR);
}

void	get_name(t_asm *asmbly, char *str)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (str[i] && str[i] != '"')
		i++;
	i++;
	if (!(str[i]))
		print_error(str);
	while (str[i + y] && str[i + y] != '"')
		y++;
	if (!(str[i + y]))
		print_error(str);
	if (!(asmbly->name = ft_strsub(str, i, y)))
		exit(ERROR);
}

void	get_comment(t_asm *asmbly, char *str)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (str[i] && str[i] != '"')
		i++;
	i++;
	if (!(str[i]))
		print_error(str);
	while (str[i + y] && str[i + y] != '"')
		y++;
	if (!(str[i + y]))
		print_error(str);
	if (!(asmbly->comment = ft_strsub(str, i, y)))
		exit(ERROR);
}
