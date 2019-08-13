#include "../../includes/vm.h"

void	init_ncurse(t_corewar *cor)
{
	initscr();
	cor->render.main = subwin(stdscr, BOX_LINES_1, BOX_COL_1, 0, 0);
	cor->render.menu = subwin(stdscr, BOX_LINES_1, BOX_COL_2, 0, BOX_COL_1);
	cor->render.commands = subwin(stdscr, 15, 50, CMD_STARTY, CMD_STARTX);
	wborder(cor->render.main, '*', '*', '*', '*', '*', '*', '*', '*');
	wborder(cor->render.menu, ' ', '*', '*', '*', '*', '*', '*', '*');
	wborder(cor->render.commands, ' ', '*', '*', '*', '*', '*', '*', '*');
	ft_bzero(cor->render.mem_owner, MEM_SIZE);
	init_colors();
	noecho();
	cbreak();
	//keypad(stdscr, TRUE);
	
	curs_set(0);
}

void	init_colors(void)
{
	start_color();
	use_default_colors();
	init_color(DARK_GREY, 169, 169, 169);
	init_color(LIGHT_GREY, 400, 400, 400);

	init_color(5, 0, 700, 700);

	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, LIGHT_GREY, LIGHT_GREY);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, LIGHT_CYAN, COLOR_BLACK);

	init_pair(6, LIGHT_GREY, LIGHT_GREY);
	init_pair(7, LIGHT_GREY, COLOR_BLACK);
	init_pair(8, COLOR_MAGENTA, COLOR_BLACK);


	init_pair(9, COLOR_BLACK, COLOR_GREEN);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_RED);
	init_pair(12, COLOR_BLACK, LIGHT_CYAN);


	init_pair(13, COLOR_YELLOW, COLOR_BLACK);
	


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

void	fill_border_cmd(t_corewar *cor)
{
	int i;
	
	i = -1;
	wattron(cor->render.commands, COLOR_PAIR(6));
	while (++i < 50)
	{
		mvwaddch(cor->render.commands, 0, i, '*');
		mvwaddch(cor->render.commands, 14, i, '*');
	}
	i = - 1;
	while (++i < 15)
		mvwaddch(cor->render.commands, i, 49, '*');
	wattroff(cor->render.commands, COLOR_PAIR(6));
}

void	draw_command(t_corewar *cor)
{
	wattron(cor->render.commands, COLOR_PAIR(13));
	wattron(cor->render.commands, A_BOLD);
	mvwprintw(cor->render.commands, 2, 17, "COMMANDS MENU");
	wattroff(cor->render.commands, A_BOLD);
	mvwprintw(cor->render.commands, 6, 10, "SPACE :  PAUSE / UNPAUSE");
	mvwprintw(cor->render.commands, 8, 10, "Q :  QUIT");
	wattroff(cor->render.commands, COLOR_PAIR(13));
}

void    close_ncurse(t_corewar *cor)
{
	delwin(cor->render.main);
	delwin(cor->render.menu);
	endwin();
}


