/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:10:08 by ratin             #+#    #+#             */
/*   Updated: 2019/08/16 14:14:08 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

char	*get_file_name(char *path)
{
	int 		i;
	char		*name;

	i = ft_strlen(path);
	if (ft_strchr(path, '/') != NULL)
	{
		while (i > 0)
		{
			if (path[i] == '/')
				break ;
			i--;
		}
		i++;
		name = ft_strsub(path, i, ft_strlen(path) - i);
		return (name);
	}
	return(ft_strdup(path));
}

void	create_file(t_corewar *cor, char *name)
{
	char		*path;
	char		*file_name;

	path = ft_strndup(name, ft_strlen(name) - 4);
	path = ft_strjoin_free(path, ".s", 1);
	file_name = get_file_name(path);
	cor->fd = open(file_name, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0644);
	if (cor->fd == -1)
		decomp_quit("error when creating the file\n");
	print_file(cor);
	ft_putstr("decompiled file at ");
	ft_putstr(path);
	ft_putstr("\n");
}
