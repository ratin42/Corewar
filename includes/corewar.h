/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:43:22 by ratin             #+#    #+#             */
/*   Updated: 2019/07/27 01:23:58 by ratin            ###   ########.fr       */
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

/*
** asm reading
*/
int			parse_file(t_asm *asmbly, char *file);
void		get_comment(t_asm *asmbly, char *str);
void		get_name(t_asm *asmbly, char *str);

/*
** instruction
*/
t_instru	*find_instru(t_asm *asmbly, int line);
int			get_opcode(t_asm *asbly, char *str, int line);
int			is_register(char *param);
int			find_op_index(char *opcode);
void		get_instruction(t_asm *asmbly, char *str, int line);
void		add_instru(t_asm *asmbly, int line);
void		get_params(t_asm *asmbly, char *str, int line);
void		check_params_error(t_asm *asmbly, char *str, int line);
void		print_erro_param(char *str, int line, int error);
void		get_params_type(t_asm *asmbly, char *str, int line);
void		add_param(t_instru *instru, int line, char *param);

/*
** conversion
*/
void		convert_instruction(t_asm *asmbly);
char		*reg_conver(t_param *param);
char		*dir_conver(t_param *param, t_instru *instru);
char		*ind_conver(t_param *param, t_instru *instru);
char		*fill_direct(int size, char **conv);
char		*reduce_conv(int size, char **conv);
char		*get_opc(t_instru *instru);
void		replace_label(t_asm *asmbly);
void		write_label(t_instru *instru, char *conv);
int			reverse_label(t_asm *asmbly, t_instru *instru, char *label);
int			compare_label(char *label1, char *label2);

/*
** debug
*/
void		print_instruction(t_asm *asmbly);
void		print_bytecode(char *str);
void        write_header(header_t *header);

#endif
