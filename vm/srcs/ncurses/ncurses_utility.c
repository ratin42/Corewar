#include "../../includes/vm.h"

void	highlight_process_pc(t_corewar *cor)
{
	t_plst			*process;
	unsigned int	i;
	int				id;

	process = cor->plst;
	while (process)
	{
		i = process->p.og_pc;
		id = process->p.id;
		highlight_it(cor, i, id);
		process = process->next;
	}
}

void	highlight_it(t_corewar *cor, unsigned int i, int id)
{
	unsigned char	c;

	c = cor->arena[i];
	wattron(cor->render.main, COLOR_PAIR(id + 8));
	if (cor->stealth)
		mvwprintw(cor->render.main, (i / 64) + 2, (i % 64) * 3 + 3, "ff");
	else
		mvwprintw(cor->render.main, (i / 64) + 2, (i % 64) * 3 + 3, "%.2x", c);
	wattroff(cor->render.main, COLOR_PAIR(id + 8));
}

void	set_attributes(t_corewar *cor, unsigned char color, int i)
{
	if (color == 0)
		wattron(cor->render.main, COLOR_PAIR(7));
	else
		wattron(cor->render.main, COLOR_PAIR(color));
	if (cor->render.bold[i] != 0)
		wattron(cor->render.main, A_BOLD);
}

void	unset_attributes(t_corewar *cor, unsigned char color, int i)
{
	if (color == 0)
		wattroff(cor->render.main, COLOR_PAIR(7));
	else
		wattroff(cor->render.main, COLOR_PAIR(color));
	if (cor->render.bold[i] != 0)
	{
		wattroff(cor->render.main, A_BOLD);
		cor->render.bold[i] -= 1;
	}
}
