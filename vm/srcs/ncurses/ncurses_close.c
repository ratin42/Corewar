#include "vm.h"

void	close_ncurses(t_corewar *cor)
{
	wclear(cor->render.main);
	delwin(cor->render.main);
	wclear(cor->render.menu);
	delwin(cor->render.menu);
	wclear(cor->render.commands);
	delwin(cor->render.commands);
	refresh();
	endwin();
	//CHECKER LEAKS AVEC ET SANS VISU
	//pour voir si le visu ne rajoute pas de leaks
}

void	end_visu(t_corewar *cor)
{
	wclear(cor->render.main);
	delwin(cor->render.main);
	wclear(cor->render.menu);
	delwin(cor->render.menu);
	wclear(cor->render.commands);
	delwin(cor->render.commands);
	refresh();
	ncurses_show_winner(cor);
	wait_and_close(3);
	endwin();
	//FREE ICI AUSSI
}

void	ncurses_show_winner(t_corewar *cor)
{
	int		i;

	i = -1;
	attron(COLOR_PAIR(15));
	while (++i < 50)
	{
		mvprintw(LINES / 3 - 2, (COLS / 2 - 30) + i, "*");
		mvprintw(LINES / 3 + 2, (COLS / 2 - 30) + i, "*");
	}
	i = -1;
	while (++i < 5)
	{
		mvprintw((LINES / 3 - 2) + i, (COLS / 2 - 30), "*");
		mvprintw((LINES / 3 - 2) + i, (COLS / 2 + 20), "*");
	}
	attroff(COLOR_PAIR(15));
	attron(COLOR_PAIR(13) | A_BOLD);
	mvprintw(LINES / 3, COLS / 2 - 25, "THE WINNER IS : \"%.15s\"",
			cor->player[ft_get_player_index(cor, cor->last_live_id)].name);
	attroff((COLOR_PAIR(13) | A_BOLD));
}

void	wait_and_close(int wait)
{
	refresh();
	sleep(wait);
	mvprintw(LINES / 3 + 4, COLS / 2 - 27,
			"Window will be automatically closed in 5s...");
	refresh();
	sleep(5);
}
