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
	wrefresh(cor->render.main);
}

int		is_a_player_pc(t_corewar *cor, int i)
{
	/*
	t_plst	*p;

	p = cor->plst;
	while (p)
	{
		if (p->p.id == i + 1)
			return (p->p.id);
		p = p->next;
	}
	*/
	(void)i;
	(void)cor;
	return (0);
	
}


void	set_attributes(t_corewar *cor, unsigned char color, int i)
{
	int ret;
	
	ret = is_a_player_pc(cor, i);
	if (color == 0)
		wattron(cor->render.main, COLOR_PAIR(7));
	else if (ret != 0)
	{
		wattron(cor->render.main, COLOR_PAIR(ret + 8 ));
	}
	else
		wattron(cor->render.main, COLOR_PAIR(color));
}

void	unset_attributes(t_corewar *cor, unsigned char color, int i)
{
	int ret;

	ret = is_a_player_pc(cor, i);
	if (color == 0)
		wattroff(cor->render.main, COLOR_PAIR(7));
	else if (ret != 0)
	{
		wattroff(cor->render.main, COLOR_PAIR(ret + 8));
	}
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
}

void	update_window(t_corewar *cor)
{
	draw_arena(cor);
	draw_menu(cor);
	ncurse_events(cor);
}




