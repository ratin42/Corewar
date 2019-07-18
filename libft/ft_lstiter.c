/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:23:30 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:10:03 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *tmp;

	if (lst == NULL || f == NULL)
		return ;
	tmp = lst;
	while (tmp != NULL)
	{
		f(tmp);
		tmp = tmp->next;
	}
}
