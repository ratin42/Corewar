#include "../includes/vm.h"

void	read_process(char *name, t_corewar *cor, int i)
{
	int					fd;
	unsigned int		size;
	unsigned int		file;
	unsigned int		size_cpy;

	t_header			*header;

	if (!(header = (t_header*)malloc(sizeof(t_header))))
		corewar_quit("Couldn't allocate t_header");
	if ((fd = open(name, O_RDONLY)) < 0)
		corewar_quit("Open error");
	if ((read(fd, header, sizeof(t_header)) < 0))
		corewar_quit("Read error");
	size = swap_endian(header->prog_size);
	//Reste a connaitre la taille minimum du champion;
	if (size > CHAMP_MAX_SIZE)
	{
		printf("Champion [%s] = %d bytes, maximum is : %d bytes", name, size, CHAMP_MAX_SIZE);
		corewar_quit("");
	}
	size_cpy = size;
	while ((int)size > 0)
	{
		if ((read(fd, &file, sizeof(unsigned int))) < 0)
			corewar_quit("Read error");
		file = swap_endian(file);
		//printf("%x\n", file);
		size -= sizeof(unsigned int);
	}
	cor->process[i].prog_name = header->prog_name;
	cor->process[i].comment = header->comment;
	cor->process[i].magic = COREWAR_EXEC_MAGIC;
	cor->process[i].prog_size = size_cpy;
	free(header);
}
