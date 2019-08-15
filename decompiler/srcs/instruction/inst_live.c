#include "decompile.h"

void                inst_live(t_corewar *cor)
{
	char	*param1;

	param1 = get_big_dir(cor);
	write(cor->fd, "live ", 5);
	write(cor->fd, param1, ft_strlen(param1));
	write(cor->fd, "\n", 1);
	free(param1);
}
