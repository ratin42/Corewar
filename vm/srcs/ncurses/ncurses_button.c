#include "../../includes/vm.h"

void	draw_play(t_corewar *cor)
{
	draw_play_1(cor, 49, 24, 6);
	draw_play_2(cor, 49, 24, 10);
	mvwprintw(cor->render.menu, 1, 28, "*** LIVE ***");
}

void	draw_play_1(t_corewar *cor, int x, int x1, int y1)
{
	int y;

	y = 4;
	while (y++ < 16)
		mvwprintw(cor->render.menu, y, 25, "#");
	y = 10;
	while (x1 >= 0 && y1 >= 0)
	{
		mvwprintw(cor->render.menu, y - y1, x - x1, "#");
		x1 -= 4;
		y1--;
	}

}

void	draw_play_2(t_corewar *cor, int x, int x1, int y)
{
	int y1;

	y1 = 6;
	while (x1 >= 0 && y1 >= 0)
	{
		mvwprintw(cor->render.menu, y + y1, x - x1, "#");
		x1 -= 4;
		y1--;
	}
}

void	draw_pause(t_corewar *cor)
{
	int y;

	y = 3;
	while (y++ < 14)
		mvwprintw(cor->render.menu, y, 23, "#");
	y = 3;
	while (y++ < 14)
		mvwprintw(cor->render.menu, y, 24, "#");
	y = 3;
	while (y++ < 14)
		mvwprintw(cor->render.menu, y, 45, "#");
	y = 3;
	while (y++ < 14)
		mvwprintw(cor->render.menu, y, 46, "#");

	mvwprintw(cor->render.menu, 1, 28, "*** PAUSED ***");



}
