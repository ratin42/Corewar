/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:33:14 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/28 16:34:25 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>

uint32_t	swap_endian(uint32_t val)
{
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
	return ((val << 16) | (val >> 16));
}

static int	ft_ucount_digit_base(unsigned int n, int base)
{
	int length;

	length = 1;
	while (n /= base)
		length++;
	return (length);
}

char		*ft_uitoa_base(unsigned int n, int base)
{
	char	*value;
	char	*tabval;
	int		len;

	len = ft_ucount_digit_base(n, base);
	if (!(value = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tabval = "0123456789abcdef";
	value[len--] = '\0';
	if (n == 0)
		value[0] = '0';
	while (n != 0)
	{
		value[len--] = tabval[n % base];
		n /= base;
	}
	return (value);
}

// void rev_print(char *s,int i)
// {
// 	int p1;
// 	int p2;
// 	char aff;

// 	p1 = 0;
// 	p2 = 0;
// 	while (s[p2] && s[p2] != ' ')
// 		p2++;
// 	if (s[p2] == ' ')
// 		rev_print(s + p2 + 1, 0);
// 	while(p1 < p2)
// 	{
// 		aff = s[p1++];
// 		write(1, &aff, 1);
// 	}
// 	if (!i)
// 		write(1, " ", 1);
// }

void        write_header(header_t *header)
{
	header->magic = swap_endian(COREWAR_EXEC_MAGIC);
	// header->prog_name = get_name();
	header->prog_size = swap_endian(header->prog_size);
	// header->comment = get_comment();
	printf("\n---------- Magic ---------------\n");
	print_bytecode(ft_uitoa_base(header->magic, 16));
	printf("---------- Name ----------------\n");
	print_bytecode(header->prog_name);
	printf("---------- Prog_size -----------\n");
	print_bytecode(ft_uitoa_base(header->prog_size, 16));
	printf("---------- Comment -------------\n");
	print_bytecode(header->comment);
}

// need to add the fd in write_header()