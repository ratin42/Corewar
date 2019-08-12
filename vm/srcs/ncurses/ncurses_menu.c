#include "../../includes/vm.h"

void	draw_menu(t_corewar *cor)
{
	fill_border_menu(cor);
	draw_infos(cor);
}

void	draw_infos(t_corewar *cor)
{
	mvwprintw(cor->render.menu, 19, 3, "Cycle : %d", cor->total);
}
