#include "disassembler.h"

void	stock_process_name(t_corewar *cor, t_header *header)
{
	int size;

	size = ft_strlen(header->prog_name);
	if (size > PROG_NAME_LENGTH)
		decomp_quit("Champion has a too big .name value\n");
	ft_strcpy(cor->name, header->prog_name);
}

void	stock_process_size(t_corewar *cor, t_header *header)
{
	int size;

	size = swap_endian(header->prog_size);
	cor->size = size;
}

void	stock_process_comment(t_corewar *cor, t_header *header)
{
	int size;

	size = ft_strlen(header->comment);
	if (size > COMMENT_LENGTH)
		decomp_quit("Champion has a too big .comment value\n");
	ft_bzero((char*)cor->comment, sizeof(COMMENT_LENGTH));
	ft_strcpy(cor->comment, header->comment);
}

void	stock_process_magic(t_corewar *cor, t_header *header)
{
	unsigned int magic;

	magic = swap_endian(header->magic);
	if (magic != COREWAR_EXEC_MAGIC)
		decomp_quit("Champion has wrong magic\n");
	cor->magic = magic;
}

void	stock_process_code(t_corewar *cor, int fd)
{
	if (!(cor->code = ft_memalloc(sizeof(unsigned char) * cor->size)))
		decomp_quit("Malloc error\n");
	if ((read(fd, cor->code, cor->size) < 0))
		decomp_quit("Read error\n");
}

