#include "../../includes/vm.h"

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
			set_attributes(cor, color);
			if (cor->stealth)
				mvwprintw(cor->render.main, y + 2, x * 3 + 3, "ff");
			else
				mvwprintw(cor->render.main, y + 2, x * 3 + 3, "%.2x", c);
			mvwprintw(cor->render.main, y + 2, x * 3 + 5, " ");
			unset_attributes(cor, color);
			i++;
		}
	}
}

void	set_attributes(t_corewar *cor, unsigned char color)
{
	if (color == 0)
		wattron(cor->render.main, COLOR_PAIR(7));
	else
		wattron(cor->render.main, COLOR_PAIR(color));
}

void	unset_attributes(t_corewar *cor, unsigned char color)
{
	if (color == 0)
		wattroff(cor->render.main, COLOR_PAIR(7));
	else
		wattroff(cor->render.main, COLOR_PAIR(color));
}

void	draw_window(t_corewar *cor)
{
	wclear(cor->render.main);
	draw_arena(cor);
	fill_border_main(cor);
	//draw_menu(cor);
	if (cor->pause == 1)
	{
		wclear(cor->render.menu);
		draw_menu(cor);
		draw_pause(cor);
		//wrefresh(cor->render.menu);
		pause_game(cor);
	}
	else
	{
		wclear(cor->render.menu);
		draw_menu(cor);
		draw_play(cor);
		//ncurse_events(cor);
		wrefresh(cor->render.main);
	}
	//doupdate();
}





