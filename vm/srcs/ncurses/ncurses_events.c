#include "../../includes/vm.h"


void	ncurse_events(t_corewar *cor)
{
	int keycode;

	keycode = getch();
	if (keycode == SPACE_BAR)
	{
		if (cor->pause == 1)
			cor->pause = 0;
		else
			cor->pause = 1;
	}
	else if (keycode == QUIT)
	{
		//free_what_needed
		close_ncurse(cor);
		corewar_quit("Game closed, Q has been pressed");
	}
}


void	pause_game(t_corewar *cor)
{
	int keycode;

	while (42)
	{
		keycode = getch();
		if (keycode == SPACE_BAR)
		{
			cor->pause = 0;
			draw_window(cor);
			return;
		}
		else if (keycode == QUIT)
		{
			//free_what_needed
			close_ncurse(cor);
			corewar_quit("Game closed, Q has been pressed");
		}
	}
}
