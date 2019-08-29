#include "disassembler.h"

void	read_process(char *name, t_corewar *cor)
{
	t_header	header;
	int			fd;

	if ((fd = open(name, O_RDONLY)) < 0)
		decomp_quit("Open error");
	if ((read(fd, &header, sizeof(t_header)) < 0))
		decomp_quit("Read error");
	stock_process_name(cor, &header);
	stock_process_size(cor, &header);
	stock_process_comment(cor, &header);
	stock_process_magic(cor, &header);
	stock_process_code(cor, fd);
}

