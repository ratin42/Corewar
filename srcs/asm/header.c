/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syzhang <syzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:33:14 by syzhang           #+#    #+#             */
/*   Updated: 2019/07/26 22:39:09 by syzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <fcntl.h>

static void	init_header(header_t *header)
{
	unsigned char *tmp;
	int i;
	int size;

	i = 0;
	size = sizeof(*header);
	tmp = (unsigned char *)header;
	while (i < size)
		tmp[i++] = 0;
}

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

// void reverse(char* begin, char* end) 
// { 
//     char temp; 
//     while (begin < end) { 
//         temp = *begin; 
//         *begin++ = *end; 
//         *end-- = temp; 
//     } 
// } 

// char *reverseWords(char* s) 
// { 
//     char* word_begin = s; 
//     char* temp = s; 
  
//     while (*temp) { 
//         temp++; 
//         if (*temp == '\0') { 
//             reverse(word_begin, temp - 1); 
//         } 
//         else if (*temp == ' ') { 
//             reverse(word_begin, temp - 1); 
//             word_begin = temp + 1; 
//         } 
//     } 
//     reverse(s, temp - 1); 
//     return (s);
// }

int			get_header(header_t *h, char *name, char *comment, unsigned int size)
{
	int i;
	header_t *header;

	if (!(h = (header_t *)malloc(sizeof(*header))))
		return (printf("Error\n"));
	header = h;
	init_header(header);
	header->magic = swap_endian(COREWAR_EXEC_MAGIC);
	header->prog_size = swap_endian(size);
	i = 0;
	while (name[i++])
		header->prog_name[i - 1] = name[i - 1];
	while (i < PROG_NAME_LENGTH + 1)
		header->prog_name[i++] = 0;
	i = 0;
	while (comment[i++])
		header->comment[i - 1] = comment[i - 1];
	while (i < COMMENT_LENGTH + 1)
		header->comment[i++] = 0;
	return (0);
}

void        write_header(header_t *header)
{
//	header->magic = swap_endian(COREWAR_EXEC_MAGIC);
	header->magic = COREWAR_EXEC_MAGIC;
//	header->prog_name = get_name();
	header->prog_size = 23;
//	header->prog_size = get_size(param->type, op->opcode);
//	header->prog_size = swap_endian(header->prog_size);
//	header->comment = get_comment();
	char *str;
	str = "00";
	char *name = "zork";
	char *comment = "hey";
	printf("\n---------- Magic ---------------\n");
	print_bytecode(ft_strjoin(str, ft_uitoa_base(header->magic, 16)));
//	print_bytecode(ft_uitoa_base(header->magic, 16));
	if (get_header(header, name, comment, header->prog_size) == 0)
	{
		printf("---------- Name ----------------\n");
		print_bytecode(ft_convert_base_finale(name, "0123456789abcdef"));
		printf("---------- Prog_size -----------\n");
		print_bytecode(ft_uitoa_base(swap_endian(header->prog_size), 16));
		printf("---------- Comment -------------\n");
		print_bytecode(ft_convert_base_finale(comment, "0123456789abcdef"));
	}
}

// need to add the fd in write_header()