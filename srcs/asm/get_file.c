/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:40:23 by ratin             #+#    #+#             */
/*   Updated: 2019/08/06 18:22:22 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parse_error(t_asm *asmbly)
{
	ft_putstr_fd("error no comment or no name found\n", 2);
	quit_prog(asmbly);
}

void	parse(t_asm *asmbly, char *str, int turn)
{
	if (is_empty(str) == 1)
		return ;
	if (check_comment(str) == 1)
		return ;
	else if (name_presence(str) == 1 && asmbly->got_name == 0)
		get_name(asmbly, str);
	else if (comment_presence(str) == 1 && asmbly->got_comment == 0)
		get_comment(asmbly, str);
	else if (asmbly->got_name == 1 && asmbly->got_comment == 1)
		get_instruction(asmbly, str, turn + 1);
	else
	{
		free(str);
		parse_error(asmbly);
	}
}

static int	open_file(char *str)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Can't read source file ");
		ft_putstr(str);
		ft_putchar('\n');
		exit(ERROR);
	}
	return (fd);
}

void		check_name(char *file)
{
	int		i;

	i = 0;
	if (ft_strlen(file) < 2)
	{
		ft_putstr("bad file name\n");
		exit(ERROR);
	}
	while (file[i])
		i++;
	if (file[i - 1] == 's' && file[i - 2] == '.')
		return ;
	else
	{
		ft_putstr("bad file name\n");
		exit(ERROR);
	}
}

int			parse_file(t_asm *asmbly, char *file)
{
	int		fd_file;
	char	*str;
	int		turn;

	turn = 0;
	fd_file = open_file(file);
	check_name(file);
	while (get_next_line(fd_file, &str) > 0)
	{
		parse(asmbly, str, turn);
		if (str != NULL)
			free(str);
		turn++;
	}
	//print_instruction(asmbly);
	return (SUCCESS);
}
