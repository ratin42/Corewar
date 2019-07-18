/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:15:39 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:10:31 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content != NULL)
	{
		if (!(new->content = malloc(sizeof(new->content) * (content_size + 1))))
			return (NULL);
		new->content = ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
		new->next = NULL;
	}
	else
	{
		if (!(new->content = malloc(sizeof(new->content) * (content_size + 1))))
			return (NULL);
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	return (new);
}
