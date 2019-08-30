#include "vm.h"

static inline void	stock_process_size(t_corewar *cor, t_header *header,
		char *name, int i)
{
	int size;

	size = swap_endian(header->prog_size);
	if (size > CHAMP_MAX_SIZE)
	{
		ft_printf("Champion [%s] = %d bytes, maximum is : %d bytes",
				name, size, CHAMP_MAX_SIZE);
		corewar_quit("");
	}
	if (size == 0)
	{
		ft_printf("Champ %s is too small to be a champion", name);
		corewar_quit("");
	}
	cor->process[i].size = size;
}

static inline void	stock_process_name(t_corewar *cor, t_header *header,
		char *name, int i)
{
	int size;

	size = ft_strlen(header->prog_name);
	if (size > PROG_NAME_LENGTH)
	{
		ft_printf("Champion named [%s] has a too big .name value : [%d], \
				maximum is : %d", name, size, PROG_NAME_LENGTH);
		corewar_quit("");
	}
	ft_strcpy(cor->process[i].name, header->prog_name);
}

static inline void	stock_process_comment(t_corewar *cor, t_header *header,
		char *name, int i)
{
	int size;

	size = ft_strlen(header->comment);
	if (size > COMMENT_LENGTH)
	{
		ft_printf("Champion [%s] has a too big .comment value : [%d], \
				maximum is %d", name, size, COMMENT_LENGTH);
		corewar_quit("");
	}
	ft_bzero((char*)cor->process[i].comment, sizeof(COMMENT_LENGTH));
	ft_strcpy(cor->process[i].comment, header->comment);
}

static inline void	stock_process_magic(t_corewar *cor, t_header *header,
		char *name, int i)
{
	unsigned int magic;

	magic = swap_endian(header->magic);
	if (magic != COREWAR_EXEC_MAGIC)
	{
		ft_printf("Champion [%s], has wrong magic : [%u], has to be : %u\n",
				name, header->magic, COREWAR_EXEC_MAGIC);
	}
	cor->process[i].magic = magic;
}

void				read_process(char *name, t_corewar *cor, int i)
{
	t_header			header;
	int					fd;

	if ((fd = open(name, O_RDONLY)) < 0)
		corewar_quit("Open error");
	if ((read(fd, &header, sizeof(t_header)) < 0))
		corewar_quit("Read error");
	stock_process_name(cor, &header, name, i);
	stock_process_size(cor, &header, name, i);
	stock_process_comment(cor, &header, name, i);
	stock_process_magic(cor, &header, name, i);
	ft_bzero((unsigned char *)cor->process[i].code, cor->process[i].size);
	if ((read(fd, cor->process[i].code, cor->process[i].size) < 0))
		corewar_quit("Read error");
	if (cor->order != 0)
	{
		cor->process[i].order = cor->order;
		cor->order = 0;
	}
	else
		cor->process[i].order = -1;
}
