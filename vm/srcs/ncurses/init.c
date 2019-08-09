#include "../../includes/vm.h"

void	init_ncurse(t_corewar *cor)
{
	initscr();
	cor->render.main = subwin(stdscr, LINES_MAIN, COLS / 2, 0, 0);
	cor->render.menu = subwin(stdscr, LINES_MAIN, COLS / 5, 0, COLS / 2);

	wborder(cor->render.main, '*', '*', '*', '*', '*', '*', '*', '*');
	wborder(cor->render.menu, '*', '*', '*', '*', '*', '*', '*', '*');
	//box(cor->render.main, ACS_VLINE, ACS_HLINE);
	//box(cor->render.menu, ACS_VLINE, ACS_HLINE);

	ft_bzero(cor->render.mem_owner, MEM_SIZE);

	init_colors(cor);


}

void	init_colors(t_corewar *cor)
{
	(void)cor;
	use_default_colors();
	init_pair
}

void	draw_default_mem(t_corewar *cor)
{
	int i;
	int j;
	
	(void)cor;
	i = -1;
	j = 0;
	while (++i < MEM_SIZE)
	{
		if (i == 64)
		{
			j++;
		}
		mvwaddchr(cor->render.main, i + 1, j, cor->render.mem_owner[i]);
	}
}

void	close_ncurse(t_corewar *cor)
{
	(void)cor;
	getch();
	endwin();
}