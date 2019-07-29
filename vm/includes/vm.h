#ifndef VM_H
# define VM_H

#include "../libft/includes/libft.h"

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "../../includes/op.h"

#include <stdio.h>

#define DEBUG 1

typedef	struct		s_instru
{
	//
}					t_instru;

typedef	struct		s_process
{
	struct s_header		header;
	struct s_instru		*instru;

}					t_process;


uint32_t	swap_endian(uint32_t val);

void	corewar_quit(char *str);
void	read_process(char *name);
int		parse_arguments(char *av);
int		get_infos(int ac, char **av);

#endif
