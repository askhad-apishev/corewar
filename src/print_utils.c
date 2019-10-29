/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:48:39 by gloras-t          #+#    #+#             */
/*   Updated: 2019/10/29 16:25:09 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_usage(void)
{
	ft_printf("usage: \n");
}

void	print_error(char *error_msg)
{
	ft_printf("{red}error:{eoc} %s\n", error_msg);
}

void	print_bits_ui(UI number)
{
	size_t	size;

	size = 8 * sizeof(UI);
	while (size--)
	{
		ft_printf("%c", (number & 1) ? '1' : '0');
		number >>= 1;
		if (size && !(size % 8))
			ft_printf(" ");
	}
}

void	print_bits_char(char number)
{
	size_t	size;

	size = 8 * sizeof(char);
	while (size--)
	{
		ft_printf("%c", (number & 1) ? '1' : '0');
		number >>= 1;
	}
}
