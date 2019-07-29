#include "../includes/vm.h"

int main(int ac, char **av)
{
	if (ac <= 1)
		return (0);
	else
	{
		if (get_infos(ac, av) == -1)
		{
			if (DEBUG)
				printf("\nERROR get_infos == -1\n");
			return (0);
		}
	}
	return (1);
}

void	corewar_quit(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_SUCCESS);
}

int	parse_arguments(char *av)
{
	int i;

	if (ft_strlen(av) <= 4)
		return (-1);
	i = 0;
	while (av[i])
	{
		i++;
	}
	i -= 4;
	if (ft_strncmp(&av[i], ".cor", 4))
		return (-1);
	else
		return (1);

}

int		get_infos(int ac, char **av)
{
	while (--ac)
	{
		if (parse_arguments(av[ac]) == -1)
		{
			if (DEBUG)
				printf("[%s]\t--> Not a valid .cor file\n", av[ac]);
			return (-1);
		}
		read_process(av[ac]);
	}
	return (1);
}


//doublon fonctions deja dans asm

uint32_t	swap_endian(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}

void	read_process(char *name)
{
	int					fd;
	unsigned int		size;
	unsigned int		file;

	t_header			*header;

	if (!(header = (t_header*)malloc(sizeof(t_header))))
		corewar_quit("Couldn't allocate t_header");
	if ((fd = open(name, O_RDONLY)) < 0)
		corewar_quit("Open error");
	if ((read(fd, header, sizeof(t_header)) < 0))
		corewar_quit("Read error");
	size = swap_endian(header->prog_size);
	while ((int)size > 0)
	{
		if ((read(fd, &file, sizeof(unsigned int))) < 0)
			corewar_quit("Read error");
		file = swap_endian(file);
		printf("%x\n", file);
		size -= sizeof(unsigned int);
	}
	
	printf("\n");
	//OK  ICI dans la boucle ont lie bien petit a petit tout les hexa
	//ils faut rajouter les 0 manquants et commencer a les stoquer;

	if (DEBUG)
	{
		printf("size = %u\n", header->prog_size);
		printf("magic = %u\n", header->magic);
		printf("prog_name = |%s|\n", header->prog_name);
		printf("comment = |%s|\n", header->comment);
	}

	//free?



}
