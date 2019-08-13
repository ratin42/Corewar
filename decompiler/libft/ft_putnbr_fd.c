/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saouas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:58:58 by saouas            #+#    #+#             */
/*   Updated: 2018/11/21 20:14:13 by saouas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		ft_putchar_fd('-', fd);
		nb2 = nb2 * -1;
	}
	if (nb2 >= 0 && nb2 < 10)
	{
		ft_putchar_fd(nb2 + '0', fd);
	}
	else
	{
		ft_putnbr_fd(nb2 / 10, fd);
		ft_putchar_fd(nb2 % 10 + '0', fd);
	}
}
