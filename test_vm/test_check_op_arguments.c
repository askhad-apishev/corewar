/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_op_arguments.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 22:17:35 by slindgre          #+#    #+#             */
/*   Updated: 2020/05/02 01:40:57 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int in_arr(UC *str, char *arr[58])
{
	int i = 0;

	while (i < 58)
	{
		if (ft_strcmp((char*)str, arr[i]) == 0)
		{
			ft_printf("%d, %s", i, arr[i]);
			return TRUE;
		}
		i++;
	}
	return FALSE;
}

int main()
{
	UC	*valid[58] = {"\001",
				"\002\144", "\002\208",
				"\003\080", "\003\112"
				"\004\084",
				"\005\084",
				"\006\084", "\006\100", "\006\116", "\006\148", "\006\164", "\006\180", "\006\212", "\006\228", "\006\244",
				"\007\084", "\007\100", "\007\116", "\007\148", "\007\164", "\007\180", "\007\212", "\007\228", "\007\244",
				"\008\084", "\008\100", "\008\116", "\008\148", "\008\164", "\008\180", "\008\212", "\008\228", "\008\244",
				"\009",
				"\010\084", "\010\100", "\010\148", "\010\164", "\010\212", "\010\228",
				"\011\084", "\011\088", "\011\100", "\011\104", "\011\116", "\011\120",
				"\012",
				"\013\144", "\013\208",
				"\014\084", "\014\100", "\014\148", "\014\164", "\014\212", "\014\228",
				"\015",
				"\016\064",
				};
	int i = 0;
	int j = 0;
	UC *op_args;

	op_args = (UC*)ft_strnew(2);
	while (i < 256) {
		j = 0;
		while (j < 256) {
			op_args[0] = i;
			op_args[1] = j;
			//ft_printf("args = %08b %08b\n", op_args[0], op_args[1]);
			if (op_args[0] == 1 || op_args[0] == 9 || op_args[0] == 12 || op_args[0] == 15
			|| in_arr(op_args, valid)) {
				if (check_op_arguments(op_args) == FALSE) {
					ft_printf("args = %08b %08b\n", op_args[0], op_args[1]);
				}
				assert(check_op_arguments(op_args) == TRUE);
			}
			j++;
		}
		i++;
	}
	return (0);
}