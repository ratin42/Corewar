#include "../../includes/vm.h"

void	init_ncurse(t_corewar *cor)
{
	initscr();
	cor->render.main = subwin(stdscr, BOX_LINES_1, BOX_COL_1, 0, 0);
	cor->render.menu = subwin(stdscr, BOX_LINES_1, BOX_COL_2, 0, BOX_COL_1);
	wborder(cor->render.main, '*', '*', '*', '*', '*', '*', '*', '*');
	wborder(cor->render.menu, ' ', '*', '*', '*', '*', '*', '*', '*');
	ft_bzero(cor->render.mem_owner, MEM_SIZE);
	init_colors();

	//
	noecho();
	nocbreak();
	//

	curs_set(0);
}

void	init_colors(void)
{
	start_color();
	use_default_colors();
	init_color(DARK_GREY, 169, 169, 169);
	init_color(LIGHT_GREY, 400, 400, 400);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, LIGHT_GREY, LIGHT_GREY);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, LIGHT_GREY, LIGHT_GREY);
	init_pair(7, LIGHT_GREY, COLOR_BLACK);

}


void	fill_border_main(t_corewar *cor)
{
	int i;

	i = -1;
	wattron(cor->render.main, COLOR_PAIR(6));
	while (i++ < BOX_COL_1)
	{
		mvwaddch(cor->render.main, BOX_LINES_1 - 1, i, '*');
		mvwaddch(cor->render.main, 0, i, '*');
	}
	i = -1;
	while (++i < BOX_LINES_1)
	{
		mvwaddch(cor->render.main, i, BOX_COL_1 - 1, '*');
		mvwaddch(cor->render.main, i, 0, '*');
	}
	wattroff(cor->render.main, COLOR_PAIR(6));
}

void	fill_border_menu(t_corewar *cor)
{
	int i;

	i = -1;
	wattron(cor->render.menu, COLOR_PAIR(6));
	while (++i < BOX_COL_2)
	{
		mvwaddch(cor->render.menu, BOX_LINES_1 - 1, i, '*');
		mvwaddch(cor->render.menu, 0, i, '*');
	}
	i = -1;
	while (i++ < BOX_LINES_1)
	{
		mvwaddch(cor->render.menu, i, BOX_COL_2 - 1, '*');
	}
	wattroff(cor->render.menu, COLOR_PAIR(6));

}

void    close_ncurse(t_corewar *cor)
{
	(void)cor;
	getch();
	delwin(cor->render.main);
	delwin(cor->render.menu);
	endwin();
}


