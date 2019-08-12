#include "../../includes/vm.h"

void	draw_menu(t_corewar *cor)
{
	draw_infos(cor);
	draw_player_info(cor);
	wrefresh(cor->render.menu);
}

void	draw_player_info(t_corewar *cor)
{
	int i;
	int y;
	
	y = 40;
	i = -1;
	while (++i < cor->nb_players)
	{

		wattron(cor->render.menu, COLOR_PAIR(i + 2));
		mvwprintw(cor->render.menu, y, 3, "Player_%d : %s",
			i + 1, cor->process[i].name);
		wattroff(cor->render.menu, COLOR_PAIR(i + 2));
		y += 4;

	}
}


void	draw_infos(t_corewar *cor)
{
	draw_banner(cor);
	wattron(cor->render.menu, COLOR_PAIR(8) | A_BOLD);
	mvwprintw(cor->render.menu, 28, 3, "CYCLE_TO_DIE:  { %d }", CYCLE_TO_DIE);
	mvwprintw(cor->render.menu, 29, 3, "CYCLE_DELTA:   { %d }", CYCLE_DELTA);
	mvwprintw(cor->render.menu, 30, 3, "MAX_CHECKS:    { %d }", MAX_CHECKS);
	mvwprintw(cor->render.menu, 31, 3, "NBR_LIVE:      { %d }", NBR_LIVE);
	wattroff(cor->render.menu, COLOR_PAIR(8) | A_BOLD);
	wattron(cor->render.menu, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(cor->render.menu, 33, 3, "CYCLE:           %d", cor->total);
	mvwprintw(cor->render.menu, 34, 3, "PROCESSES:       %d", 0);
	wattroff(cor->render.menu, COLOR_PAIR(2) | A_BOLD);
}

void	draw_banner(t_corewar *cor)
{
	wattron(cor->render.menu, A_BOLD);
	wattron(cor->render.menu, COLOR_PAIR(2));
	mvwprintw(cor->render.menu, 19, 12, STR1);
	wattroff(cor->render.menu, COLOR_PAIR(2));
	wattron(cor->render.menu, COLOR_PAIR(3));
	mvwprintw(cor->render.menu, 20, 12, STR2);
	wattroff(cor->render.menu, COLOR_PAIR(3));
	wattron(cor->render.menu, COLOR_PAIR(4));
	mvwprintw(cor->render.menu, 21, 12, STR3);
	wattroff(cor->render.menu, COLOR_PAIR(4));
	wattron(cor->render.menu, COLOR_PAIR(5));
	mvwprintw(cor->render.menu, 22, 12, STR4);
	wattroff(cor->render.menu, COLOR_PAIR(5));
	wattron(cor->render.menu, COLOR_PAIR(13));
	mvwprintw(cor->render.menu, 23, 12, STR5);
	wattroff(cor->render.menu, COLOR_PAIR(13));
	wattron(cor->render.menu, COLOR_PAIR(2));
	mvwprintw(cor->render.menu, 24, 12, STR6);
	wattroff(cor->render.menu, COLOR_PAIR(2));
	wattroff(cor->render.menu, A_BOLD);
}
