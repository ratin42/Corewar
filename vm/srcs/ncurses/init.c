#include "../../includes/vm.h"

void	init_ncurse(t_corewar *cor)
{
	initscr();
	cor->render.main = subwin(stdscr, BOX_LINES_1, BOX_COL_1, 0, 0);
	cor->render.menu = subwin(stdscr, BOX_LINES_1, BOX_COL_2, 0, BOX_COL_1);

	wborder(cor->render.main, '*', '*', '*', '*', '*', '*', '*', '*');
	wborder(cor->render.menu, ' ', '*', '*', '*', '*', '*', '*', '*');

	ft_bzero(cor->render.mem_owner, MEM_SIZE);
	init_colors(cor);

	//
	noecho();
	nocbreak();
	//

	curs_set(0);
}



void	init_colors(t_corewar *cor)
{
	(void)cor;
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

	//init_pair(6, DARK_GREY, DARK_GREY);

	init_pair(6, LIGHT_GREY, LIGHT_GREY);



	//init_pair(5, COLOR_WHITE, COLOR_BLACK);


//	init_pair(5, COLOR_GREY, COLOR_BLACK);
}

void	draw_window(t_corewar *cor)
{
	draw_arena(cor);
	fill_border_main(cor);
	fill_border_menu(cor);
	

	//
	close_ncurse(cor);
}

void    draw_arena(t_corewar *cor)
{
	int x;
	int y;
	int i;

	unsigned char   c;
	unsigned char   color;
	
	i = 0;
	y = -1;
	while (++y < 64)
	{
		x = -1;
		while (++x < 64)
		{
			c = cor->arena[i];
			color = cor->render.mem_owner[i];
			wattron(cor->render.main, COLOR_PAIR(color));
			mvwprintw(cor->render.main, y + 2, x * 3 + 3, "%.2x", c);
			mvwprintw(cor->render.main, y + 2, x * 3 + 5, " ");
			wattroff(cor->render.main, COLOR_PAIR(color));
			i++;
		}
	}
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


