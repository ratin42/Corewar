/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 02:57:18 by ratin             #+#    #+#             */
/*   Updated: 2019/07/29 22:22:51 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int         atoi_hex(char *str, int fd)
{
	unsigned char res;
	int     i;
	int     y;

	i = 0;
	y = -1;
	res = 0;
	while (str[i])
	{
		if (str[i] == ';')
		{
			i++;
			continue ;
		}
		res = ((res >> 4) | (res << 4));
		if (str[i] >= 48 && str[i] <= 57)
			res = res + (str[i] - 48);
		if (str[i] >= 97 && str[i] <= 102)
			res = res + (str[i] - 87);
		if (y % 2 == 0)
		{
			write(fd, &res, sizeof(unsigned char));
			res = 0;
		}
		y++;
		i++;
	}
	return (0);
}

void			write_bytecode(t_asm *asmbly, int fd)
{
	t_instru	*instru;
	header_t	*header;

	instru = asmbly->instru;
	
	header = malloc(sizeof(header_t));
	header->magic = swap_endian(COREWAR_EXEC_MAGIC);
	header->prog_size = swap_endian(asmbly->size);
	ft_strcpy(header->prog_name, asmbly->name);
	ft_strcpy(header->comment, asmbly->comment);
	write(fd, header, sizeof(header_t));
	while (instru)
	{
		atoi_hex(instru->conv_par, fd);
		instru = instru->next;
	}
}

void			write_file(t_asm *asmbly, char *file)
{
	int			fd;
	char		*new_file;

	new_file = ft_strndup(file, ft_strlen(file) - 2);
	new_file = ft_strjoin_free(new_file, ".cor", 1);
	fd = open(new_file, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr("eror when creating the file\n");
		exit(ERROR);
	}
	free(new_file);
	write_bytecode(asmbly, fd);
}