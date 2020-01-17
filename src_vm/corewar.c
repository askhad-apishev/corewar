/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:43:42 by gloras-t          #+#    #+#             */
/*   Updated: 2020/01/17 21:02:21 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int argc, char *argv[])
{
	t_game	game;
	t_carry *carry;
	
	carry = NULL;
	init_game(&game);
	parse_args(argc, argv, &game);
	introduce_players(game);
	place_players_code(&game, &carry);
	main_cycle(&game, carry);
	
	return (0);
}
