
#include "corewar.h"

void		init_prog(t_asm *asmbly)
{
	asmbly->name = NULL;
	ft_bzero(asmbly->comment, COMMENT_LENGTH + 1);
	asmbly->instru = NULL;
	asmbly->in_comment = 0;
}

void		print_writing(char *str)
{
	int		i;
	char	*new_file;

	i = 0;
	new_file = ft_strndup(str, ft_strlen(str) - 2);
	ft_putstr("Writing output program to ");
	ft_putstr(new_file);
	ft_putstr(".cor\n");
	free(new_file);
}

int			main(int ac, char **av)
{
	t_asm	asmbly;

	if (ac < 2)
	{
		ft_putstr_fd("Usage: ./asm <sourcefile.s>\n", 2);
		exit(ERROR);
	}
	init_prog(&asmbly);
	parse_file(&asmbly, av[ac - 1]);
	dlt_lst_empty_lbl(&asmbly);
	convert_instruction(&asmbly);
	count_size(&asmbly);
	write_file(&asmbly, av[ac - 1]);
//	print_instruction(&asmbly);
	print_writing(av[ac - 1]);
	free_prog(&asmbly);
	return (0);
}

//faire les commentaire sur plusieurs ligne
//protection contre dev/ran null