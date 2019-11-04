/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 21:44:41 by gloras-t          #+#    #+#             */
/*   Updated: 2019/11/04 21:09:25 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"
# include <assert.h>

# define COR_EXTENSION		".cor"
# define UI					uint32_t
# define UC					unsigned char

typedef struct				s_player
{
	UI      			    magic;
	char					prog_name[PROG_NAME_LENGTH + 1];
	UI      			    prog_size;
	char					comment[COMMENT_LENGTH + 1];
	unsigned char			code[CHAMP_MAX_SIZE + 1];
}							t_player;

typedef struct				s_carry
{
	int						nbr;
	int						carry;
	int						op;
	int						live;
	int						timer;
	int						pos;
	int						jump;
	int						r[REG_NUMBER];
	struct s_carry			*next;
}							t_carry;

int							ft_printf(const char *restrict format, ...);

/*
** print_utils.c
*/
void						print_usage(void);
void						print_error(char *error_msg);
void						print_bits_ui(UI     number);
void						print_bits_char(char number);

/*
** check_utils_01.c
*/
int							is_cor_extension(char *file_name);
int							has_header(char *byte);


#endif
