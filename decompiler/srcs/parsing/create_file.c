/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:10:08 by ratin             #+#    #+#             */
/*   Updated: 2019/08/15 22:36:20 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decompile.h"

void	create_file(t_corewar *cor, char *name)
{
	char		*path;

	path = ft_strndup(name, ft_strlen(name) - 4);
	path = ft_strjoin_free(path, ".s", 1);
	cor->fd = open(path, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0644);
	if (cor->fd == -1)
		decomp_quit("error when creating the file\n");
	print_file(cor);
	ft_putstr("decompiled file at ");
	ft_putstr(path);
	ft_putstr("\n");
}