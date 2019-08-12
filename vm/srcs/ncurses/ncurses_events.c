#include "../../includes/vm.h"


void	ncurse_events(t_corewar *cor)
{
	int keycode;
	
	nodelay(stdscr, 1);	
	keycode = getch();
	if (keycode == SPACE_BAR)
	{
		if (cor->pause == 1)
		{
			cor->pause = 0;
			draw_play(cor);
		}
		else
		{
			cor->pause = 1;
			pause_game(cor);
		}
	}
	if (keycode == QUIT)
	{
		//free_what_needed
		close_ncurse(cor);
		corewar_quit("Game closed, Q has been pressed");
	}
}


void	pause_game(t_corewar *cor)
{
	int keycode;
	
	draw_pause(cor);
	while (42)
	{
		keycode = getch();
		if (keycode == SPACE_BAR)
		{
			cor->pause = 0;
			draw_play(cor);
			return;
		}
		if (keycode == QUIT)
		{
			//free_what_needed
			close_ncurse(cor);
			corewar_quit("Game closed, Q has been pressed");
		}
	}
}
