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
			unset_attributes(cor, color);
			mvwprintw(cor->render.main, y + 2, x * 3 + 5, " ");
			i++;
		}
	}
	highlight_process_pc(cor);
	wrefresh(cor->render.main);
}


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
	wattroff(cor->render.main, COLOR_PAIR(id + 7));
}



int		is_a_process_pc(t_corewar *cor, unsigned int i)
{
	t_plst	*p;
	int j;


	p = cor->plst;
	j = 0;
	while (p)
	{
		if (p->p.og_pc == i)
		{
			return (p->p.id);
		}
		p = p->next;
		j++;
	}
	return (0);
	
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
	draw_arena(cor);
	fill_border_main(cor);
	fill_border_cmd(cor);
	draw_command(cor);
	pause_game(cor);
	cor->sleep = 7000;
}

void	update_window(t_corewar *cor)
{
	draw_arena(cor);
	draw_menu(cor);
	ncurse_events(cor);
	usleep(cor->sleep);
}




