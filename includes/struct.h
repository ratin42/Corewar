/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:46:31 by ratin             #+#    #+#             */
/*   Updated: 2019/07/20 22:15:37 by ratin            ###   ########.fr       */
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
	struct s_param		*next;
}						t_param;

typedef struct			s_instru
{
	char				*label;
	char				*opcode;
	char				*ocp;
	int					line;
	struct s_param		*param;
	struct s_instru		*next;
}						t_instru;

#endif