/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:43:22 by ratin             #+#    #+#             */
/*   Updated: 2019/07/21 23:50:51 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "struct.h"
# include "op.h"
# include "../libft/includes/libft.h"

# include <stdio.h>

# define ERROR				-1
# define SUCCESS			1
# define COREWAR_INSTRUCTION1 "live ld st add sub and or xor zjmp ldi sti fork"
# define COREWAR_INSTRUCTION2 "lld lldi lfork aff"

int			parse_file(t_asm *asmbly, char *file);
void		get_comment(t_asm *asmbly, char *str);
void		get_name(t_asm *asmbly, char *str);

/*
** instruction
*/
t_instru	*find_instru(t_asm *asmbly, int line);
int			get_opcode(t_asm *asbly, char *str, int line);
void		get_instruction(t_asm *asmbly, char *str, int line);
void		add_instru(t_asm *asmbly, int line);
void		get_params(t_asm *asmbly, char *str, int line);
void		fill_params(t_asm *asmbly, char *str, int line);
void		add_param(t_instru *instru, int line, char *param);


/*
** debug
*/
void			print_instruction(t_asm *asmbly);

#endif
