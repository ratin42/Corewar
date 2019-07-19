/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:43:22 by ratin             #+#    #+#             */
/*   Updated: 2019/07/19 16:36:53 by ratin            ###   ########.fr       */
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

int	 parse_file(t_asm *asmbly, char *file);
void get_comment(t_asm *asmbly, char *str);
void get_name(t_asm *asmbly, char *str);
void get_instruction(t_asm *asmbly, char *str);

#endif