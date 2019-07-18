/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:46:31 by ratin             #+#    #+#             */
/*   Updated: 2019/07/18 21:56:44 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
}				t_instruction;

#endif