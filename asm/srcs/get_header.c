/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 15:42:13 by ratin             #+#    #+#             */
/*   Updated: 2019/08/09 13:46:16 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_error(t_asm *asmbly, char *str)
{
	ft_putstr_fd("Lexical error for", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	
	(void)str;
	quit_prog(asmbly);
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
		print_error(asmbly, str);
	while (str[i + y] && str[i + y] != '"')
		y++;
	if (!(str[i + y]))
		print_error(asmbly, str);
	if (!(asmbly->name = ft_strsub(str, i, y)))
		quit_prog(asmbly);
	asmbly->got_name = 1;
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
		print_error(asmbly, str);
	while (str[i + y] && str[i + y] != '"')
		y++;
	if (!(str[i + y]))
		print_error(asmbly, str);
	if (!(asmbly->comment = ft_strsub(str, i, y)))
		quit_prog(asmbly);
	asmbly->got_comment = 1;
}
