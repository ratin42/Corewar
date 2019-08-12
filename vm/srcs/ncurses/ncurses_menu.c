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
		mvwprintw(cor->render.menu, y, 3, "Player_%d : %s",
			i + 1, cor->process[i].name);
		y += 4;
	}
}


void	draw_infos(t_corewar *cor)
{
	//COREWAR
	
	mvwprintw(cor->render.menu, 19, 12, STR1);
	mvwprintw(cor->render.menu, 20, 12, STR2);
	mvwprintw(cor->render.menu, 21, 12, STR3);
	mvwprintw(cor->render.menu, 22, 12, STR4);
	mvwprintw(cor->render.menu, 23, 12, STR5);
	mvwprintw(cor->render.menu, 24, 12, STR6);
	
	//INFO_1
	wattron(cor->render.menu, COLOR_PAIR(8));
	mvwprintw(cor->render.menu, 30, 3, "CYCLE_TO_DIE:  { %d }", CYCLE_TO_DIE);
	mvwprintw(cor->render.menu, 31, 3, "CYCLE_DELTA:   { %d }", CYCLE_DELTA);
	mvwprintw(cor->render.menu, 32, 3, "MAX_CHECKS:    { %d }", MAX_CHECKS);
	mvwprintw(cor->render.menu, 33, 3, "NBR_LIVE:      { %d }", NBR_LIVE);
	wattroff(cor->render.menu, COLOR_PAIR(8));
	
	//INFO_2
	wattron(cor->render.menu, COLOR_PAIR(2) | A_BOLD);
	mvwprintw(cor->render.menu, 35, 3, "CYCLE:           %d", cor->total);
	mvwprintw(cor->render.menu, 36, 3, "PROCESSES:       %d", 0);
	wattroff(cor->render.menu, COLOR_PAIR(2) | A_BOLD);
}
