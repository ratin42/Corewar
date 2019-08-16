#include "../includes/disassembler.h"

void	read_process(char *name, t_corewar *cor)
{
	t_header			header;
	int					fd;

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
	if (size > CHAMP_MAX_SIZE)
		decomp_quit("Champion is to big\n");
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
	ft_bzero((unsigned char *)cor->code, cor->size);
	if ((read(fd, cor->code, cor->size) < 0))
			decomp_quit("Read error");
}
