/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:46:31 by ratin             #+#    #+#             */
/*   Updated: 2019/07/19 16:18:03 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_asm
{
	char				*name;
	char				*comment;
	struct s_instru		*instru;
}						t_asm;

typedef struct			s_param
{
	unsigned int		type;
	int					value;
}						t_param;

typedef struct			s_instruction
{
	char				*label;
	int					opcode;
	int					ocp;
	struct s_param		*param;
}						t_instru;

#endif