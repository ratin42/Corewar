/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decompile.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:17:25 by ratin             #+#    #+#             */
/*   Updated: 2019/08/13 23:29:43 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECOMPILE_H
# define DECOMPILE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "struct.h"
# include "../libft/includes/libft.h"
# include "../../asm/includes/op.h"
# include <stdio.h>

# define ERROR				-1
# define SUCCESS			1

typedef struct 			s_corewar
{
	unsigned char		arena[MEM_SIZE];
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH];
	unsigned char		code[CHAMP_MAX_SIZE];
	unsigned int		size;
	unsigned int		magic;
	unsigned int 		pc;
	int					fd;
}						t_corewar;

typedef struct			s_plst
{
	struct s_plst		*next;
	int					pc;
}						t_plst;

uint32_t	swap_endian(uint32_t val);
void		read_process(char *name, t_corewar *cor);
void		decomp_quit(char *str);
void		create_file(t_corewar *cor, char *name);
void		print_file(t_corewar *cor);

void		stock_process_name(t_corewar *cor, t_header *header);
void		stock_process_size(t_corewar *cor, t_header *header);
void		stock_process_code(t_corewar *cor, int fd);
void		stock_process_comment(t_corewar *cor, t_header *header);
void		stock_process_magic(t_corewar *cor, t_header *header);

//DEBUG
void	print_champion(t_corewar *cor);
#endif