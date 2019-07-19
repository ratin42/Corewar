/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:40:23 by ratin             #+#    #+#             */
/*   Updated: 2019/07/19 16:35:16 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		parse(t_asm *asmbly, char *str, int	turn)
{
	if (ft_strcmp(str, ""))
		return ;
	if (str[0] == COMMENT_CHAR)
		return ;
	else if (turn == 0)
		get_name(asmbly, str);
	else if (turn == 1)
		get_comment(asmbly, str);
	else
		get_instruction(asmbly, str);
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
	while (get_next_line(fd_file, &str) == 1)
	{
		parse(asmbly, str, turn);
		str ? free(str) : 0;
		turn++;
	}
	return (SUCCESS);
}