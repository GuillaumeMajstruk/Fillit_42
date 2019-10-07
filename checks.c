/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guillaume <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 07:45:09 by guillaume         #+#    #+#             */
/*   Updated: 2018/06/29 15:50:07 by gmajstru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_argc(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit arg_file\n");
		exit(0);
	}
}

t_bool	check_block_count(char const *tet_str)
{
	t_iterator	it;
	int			b_count;

	it = 0;
	b_count = 0;
	while (it < PARTS_NB)
	{
		if (tet_str[it] == TET_PART)
			b_count++;
		it++;
	}
	return (b_count);
}

t_bool	check_endl(char const *tet_str)
{
	t_iterator	it;

	it = 0;
	while (it < PARTS_NB)
	{
		if (tet_str[it] == ENDL &&
			(it != 4 && it != 9 && it != 14 && it != 19))
			return (FALSE);
		it++;
	}
	if (tet_str[4] != ENDL || tet_str[9] != ENDL ||
		tet_str[14] != ENDL || tet_str[19] != ENDL)
		return (FALSE);
	return (TRUE);
}

t_bool	tet_is_valide(char const *tet_str)
{
	t_iterator	it;
	int			b_count;

	it = 0;
	b_count = 0;
	while (it < PARTS_NB)
	{
		if (tet_str[it] != TET_EMPTY && tet_str[it] != TET_PART &&
		tet_str[it] != ENDL)
			return (FALSE);
		if (tet_str[it] == TET_PART)
		{
			if ((it + 1) < 20 && tet_str[it + 1] == TET_PART)
				b_count++;
			if ((it - 1) >= 0 && tet_str[it - 1] == TET_PART)
				b_count++;
			if ((it + 5) < 20 && tet_str[it + 5] == TET_PART)
				b_count++;
			if ((it - 5) >= 0 && tet_str[it - 5] == TET_PART)
				b_count++;
		}
		it++;
	}
	return ((b_count == 6 || b_count == 8) &&
			check_block_count(tet_str) == 4 && check_endl(tet_str) ? 1 : 0);
}
