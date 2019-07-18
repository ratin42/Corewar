/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:32:38 by saouas            #+#    #+#             */
/*   Updated: 2019/06/05 00:35:50 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*ft_parse_tmp(char *save, char **line)
{
	char	*tmp;

	tmp = NULL;
	if ((tmp = ft_strchr(save, 10)))
	{
		*tmp = 0;
		if (!(tmp = ft_strdup(tmp + 1)))
			return (NULL);
		if (!(*line = ft_strdup(save)))
			return (NULL);
		ft_strdel(&save);
		save = tmp;
	}
	else
	{
		if (!(*line = ft_strdup(save)))
			return (NULL);
		ft_strclr(save);
	}
	return (save);
}

int		ft_strrdel(int ret, char *save)
{
	ft_strdel(&save);
	return (ret);
}

int		check_zero(char *str, int ret)
{
	if (str[ret] == '\0' && str[ret - 1] == '\0')
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*save;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	if (!save && !(save = ft_strnew(0)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (ret);
		buf[ret] = '\0';
		if (check_zero(buf, ret) == 0)
			return (0);
		if (!(save = ft_strdjoin(save, buf)))
			return (-1);
		if (ft_strchr(buf, 10))
			break ;
	}
	if (ret <= 0 && !(*save))
		return (ret);
	if (!(save = ft_parse_tmp(save, line)))
		return (ft_strrdel(ret, save));
	return (1);
}
