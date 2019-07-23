/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:40:23 by ratin             #+#    #+#             */
/*   Updated: 2019/07/23 21:48:05 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	is_empty(char *str)
{
	int		i;

	i = 0;
	if (ft_strcmp(str, "") == 0)
		return (1);
	while (str[i])
	{
		if (str[i] != 32 && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

void		parse(t_asm *asmbly, char *str, int turn)
{
	if (is_empty(str) == 1)
		return ;
	if (str[0] == COMMENT_CHAR)
		return ;
	else if (turn == 0)
		get_name(asmbly, str);
	else if (turn == 1)
		get_comment(asmbly, str);
	else
		get_instruction(asmbly, str, turn + 1);
}

static int	open_file(char *str)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr("Can't read source file ");
		ft_putstr(str);
		ft_putchar('\n');
		exit(ERROR);
	}
	return (fd);
}

int			parse_file(t_asm *asmbly, char *file)
{
	int		fd_file;
	char	*str;
	int		turn;

	turn = 0;
	fd_file = open_file(file);
	while (get_next_line(fd_file, &str) > 0)
	{
		parse(asmbly, str, turn);
		if (str != NULL)
			free(str);
		turn++;
	}
	return (SUCCESS);
}
