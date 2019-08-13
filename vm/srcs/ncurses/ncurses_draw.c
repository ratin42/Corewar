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
			set_attributes(cor, color, i);
			if (cor->stealth)
				mvwprintw(cor->render.main, y + 2, x * 3 + 3, "ff");
			else
				mvwprintw(cor->render.main, y + 2, x * 3 + 3, "%.2x", c);
			unset_attributes(cor, color, i);
			mvwprintw(cor->render.main, y + 2, x * 3 + 5, " ");
			i++;
		}
	}
	highlight_process_pc(cor);
	wrefresh(cor->render.main);
}

void	draw_window(t_corewar *cor)
{
	draw_arena(cor);
	fill_border_main(cor);
	fill_border_cmd(cor);
	draw_command(cor);
	pause_game(cor);
	cor->sleep = 10000;
}

void	draw_menu(t_corewar *cor)
{
	draw_infos(cor);
	draw_player_info(cor);
	wrefresh(cor->render.menu);
}

void	update_window(t_corewar *cor)
{
	draw_arena(cor);
	draw_menu(cor);
	ncurse_events(cor);
	usleep(cor->sleep);
}
