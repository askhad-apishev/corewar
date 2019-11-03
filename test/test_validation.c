/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 16:26:01 by gloras-t          #+#    #+#             */
/*   Updated: 2019/11/03 00:50:59 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

enum octet
{
	FIRST = 0,
	SECOND = 8,
	THIRD = 16,
	FORTH = 24
};

char	convert_ui_to_char(UI number, UI octet)
{
	char	c;
	size_t	size;
	UI		tmp;
	UI		offset;

	c = 0;
	tmp = 0;
	offset = octet;
	size = 8 * sizeof(char);
	while (size--)
	{
		tmp = number & (1 << octet);
		tmp >>= offset;
		c |= tmp;
		octet++;
	}
	return c;
}

int main()
{
	char	buf[4];
	buf[0] = 0x00;	buf[1] = 0xEA;	buf[2] = 0x83;	buf[3] = 0xF3;
	assert(has_header(buf));

	ft_bzero(buf, 4);
	assert(!has_header(buf));

	buf[0] = 0xF3; buf[1] = 0x83; buf[2] = 0xEA; buf[3] = 0x00;
	assert(!has_header(buf));

	buf[0] = 0x00; buf[1] = 0x83; buf[2] = 0xEA; buf[3] = 0xF3;
	assert(!has_header(buf));

	buf[0] = 0x00; buf[1] = 0xEA; buf[2] = 0x00; buf[3] = 0x00;
	assert(!has_header(buf));

	buf[0] = 0x00 + 1; buf[1] = 0xEA; buf[2] = 0x83; buf[3] = 0xF3;
	assert(!has_header(buf));

	buf[0] = 1; buf[1] = 1; buf[2] = 1; buf[3] = 1;
	assert(!has_header(buf));

	ft_printf("{green}OK{eoc} {yellow}has_header(char *byte);{eoc}\n");
/*
	print_bits_ui(COREWAR_EXEC_MAGIC);
	ft_printf("\n");
	print_bits_char(convert_ui_to_char(COREWAR_EXEC_MAGIC, FIRST));
	ft_printf("\n");
	print_bits_char(convert_ui_to_char(COREWAR_EXEC_MAGIC, SECOND));
	ft_printf("\n");
	print_bits_char(convert_ui_to_char(COREWAR_EXEC_MAGIC, THIRD));
	ft_printf("\n");
	print_bits_char(convert_ui_to_char(COREWAR_EXEC_MAGIC, FORTH));
*/
    return (0);
}